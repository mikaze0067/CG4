#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {

	// ゲームシーンのインスタンス生成
	backGround = new BackGround();
	// ゲームシーンの初期化
	backGround->Initialize();
}

void GameScene::Update() {

	backGround->Update();
}

void GameScene::Draw() {

	backGround->Draw(); 
}