#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {// 3Dモデルデータの解放
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelEffect_= Model::Create();

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(modelEffect_);
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