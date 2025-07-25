#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	//model2_ = Model2::CreateFromOBJ("player", true);
	model2_ = Model2::CreateSquare();

	// カメラの初期化
	camera_.Initialize();

	Vector3 position = {0.0f, 0.0f, 0.0f};

	// パーティクルの生成
	player_ = new Player();
	// パーティクルの初期化
	player_->Initialize(model2_, position);

		// ゲームシーンのインスタンス生成
	backGround = new BackGround();
	// ゲームシーンの初期化
	backGround->Initialize();
}

void GameScene::Update() { backGround->Update(); }

void GameScene::Draw() {

// DirectXCommon インスタンスの取得
	dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	backGround->Draw();

	// 3Dモデル描画後処理
	Sprite::PostDraw();

	//深度バッファ
	dxCommon->ClearDepthBuffer();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());
	// パーティクル描画
	player_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();

	

}

