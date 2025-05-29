#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


GameScene::~GameScene() {// 3Dモデルデータの解放
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	// カメラの初期化
	camera_.Initialize();	


	// 乱数の初期化
	srand((unsigned)time(NULL));
}


void GameScene::Update() {

	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		// パーティクルの発生
		ParticleBorn(position);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}
	// 終了フラグの立ったパーティクルを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			effect->Update();
			return true;
		}
		return false;
	});
}

void GameScene::Draw() {
	//DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());
	// パーティクル描画
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 position) {
	// パーティクルの生成
	for (int i = 0; i < 10; i++) {
		Effect* effect = new Effect();

		Vector3 scale = {1.0f, std::abs(distribution(randomEngine) * 10.0f), 1.0f};

		Vector3 rotation = {0.0f, 0.0f, distribution(randomEngine) * 10.0f};

		// パーティクルの初期化
		effect->Initialize(modelEffect_, position, scale, rotation);
		// リストに追加
		effects_.push_back(effect);
	}
}

