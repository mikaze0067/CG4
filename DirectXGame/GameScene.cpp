#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() { Model2::StaticFinalize(); }

void GameScene::Initialize() {

	Model2::StaticInitialize();

}

void GameScene::Update() {}

void GameScene::Draw() {}

