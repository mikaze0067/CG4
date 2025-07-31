#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() : hpRatio_(1.0f) {}

GameScene::~GameScene() {
	Model2::StaticFinalize();
	delete backGround;
	delete player_;
	delete graphBar_;
	delete score_;
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

	score_ = new Score();
	score_->Initialize(Vector2(50, 50));
}

void GameScene::Update() {
	backGround->Update();
	player_->Update();

	// HPバーの値を減らす
	hpRatio_ -= 0.005f;
	if (hpRatio_ < 0.0f) {
		hpRatio_ = 1.0f;
	}

	if (graphBar_) {
		graphBar_->Update(hpRatio_);
	}

	if (score_) {
		static int testScore = 0;
		testScore += 1;
		score_->SetScore(testScore);
	}
}

void GameScene::Draw() {
	dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	backGround->Draw();

	if (graphBar_) {
		graphBar_->Draw();
	}

	if (score_) {
		score_->Draw();
	}

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	if (player_) {
		player_->Draw(camera_);
	}

	Model2::PostDraw();
}
