#pragma once
#include "KamataEngine.h"
#include "Model2.h"
#include "Player.h"
#include "BackGround.h"
#include "GraphBar.h"
#include "Score.h"

// ゲームシーン
class GameScene {
public:

	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();


private:

	KamataEngine::DirectXCommon* dxCommon = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// 3Dモデルデータ
	KamataEngine::Model2* model2_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	// エフェクト
	Player* player_ = nullptr;

	BackGround* backGround = nullptr;

	GraphBar* graphBar_ = nullptr;
	float hpRatio_ = 1.0f;
	Score* score_ = nullptr;
};