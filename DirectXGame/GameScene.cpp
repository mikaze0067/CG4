#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	model2_ = Model2::Create();
}

void GameScene::Update() {}

void GameScene::Draw() {

// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());
	// パーティクル描画
	//model2_->Draw();

	// 3Dモデル描画後処理
	Model::PostDraw();
}

