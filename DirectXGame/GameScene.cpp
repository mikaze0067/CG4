#include "GameScene.h"

using namespace KamataEngine;


GameScene::~GameScene() {
	// 3Dモデルデータの解放
	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	//カメラの初期化
	camera_.Initialize();

	//パーティクルの生成
	particle_ = new Particle();
	//パーティクルの初期化
	particle_->Initialize();
}

void GameScene::Update() { 

	particle_->Update();
}

void GameScene::Draw() {

}