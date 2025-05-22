#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

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
	
	// パーティクルの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(modelEffect_, position);

	// 乱数の初期化
	srand((unsigned)time(NULL));
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

