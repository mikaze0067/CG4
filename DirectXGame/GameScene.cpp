#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() : hpRatio_(1.0f) {}

GameScene::~GameScene() {
	Model2::StaticFinalize();
	delete backGround;
	delete player_;
	delete graphBar_;
}

void GameScene::Initialize() {
	Model2::StaticInitialize();

	model2_ = Model2::CreateSquare();

	camera_.Initialize();

	Vector3 position = {0.0f, 0.0f, 0.0f};

	player_ = new Player();
	player_->Initialize(model2_, position);

	backGround = new BackGround();
	backGround->Initialize();

	graphBar_ = new GraphBar();
	graphBar_->Initialize(Vector2(50, 100), Vector2(200, 20));
}

// メンバ変数としてfloat hpRatio_をGameSceneクラスに追加してください

void GameScene::Update() {
	backGround->Update();
	player_->Update();

	// HPバーの値を減らす
	hpRatio_ -= 0.005f; // 減るスピードは調整可
	if (hpRatio_ < 0.0f) {
		hpRatio_ = 1.0f; // 0になったら戻す
	}

	if (graphBar_) {
		graphBar_->Update(hpRatio_);
	}
}

void GameScene::Draw() {
	dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	backGround->Draw();

	if (graphBar_) {
		graphBar_->Draw();
	}

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	if (player_) {
		player_->Draw(camera_);
	}

	Model2::PostDraw();
}
