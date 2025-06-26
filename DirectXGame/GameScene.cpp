#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	model2_ = Model2::Create();

	// カメラの初期化
	camera_.Initialize();

	Vector3 position = {0.0f, 0.0f, 0.0f};

	// パーティクルの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(model2_, position);
}

void GameScene::Update() {}

void GameScene::Draw() {

// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());
	// パーティクル描画
	effect_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}

