#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() {// 3Dモデルデータの解放
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	// カメラの初期化
	camera_.Initialize();


	// パーティクルの生成
	effect_ = new Effect();
	// 位置
	Vector3 position = {0.0, 0.0f, 0.0f};
	// 移動量
	Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
	Normalize(velocity);
	velocity *= distribution(randomEngine);
	velocity *= 0.1f;
	// パーティクルの初期化
	effect_->Initialize(modelEffect_, position, velocity);

	// Y軸方向のスケールを 0.5〜1.5 の範囲でランダムに設定
	float scaleY = std::uniform_real_distribution<float>(0.5f, 1.5f)(randomEngine);

	// Z軸の回転を -π 〜 π の範囲でランダムに設定
	float rotationZ = std::uniform_real_distribution<float>(-3.14159f, 3.14159f)(randomEngine);

	// パーティクル初期化
	effect_->Initialize(modelEffect_, position, velocity);

	// 初期化後にパラメータを設定
	effect_->SetScaleY(scaleY);
	effect_->SetRotationZ(rotationZ);
}

void GameScene::Update() {
	effect_->Update();
}

void GameScene::Draw() {
	//DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());
	// パーティクル描画
	effect_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}

