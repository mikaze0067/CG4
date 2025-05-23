#pragma once
#include "KamataEngine.h"
#include "Effect.h"

using namespace KamataEngine;

// ゲームシーン
class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();



private:

	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// エフェクトの3Dモデルデータ
	Model* modelEffect_ = nullptr;
	// カメラ
	Camera camera_;
	//エフェクト
	std::list<Effect*> effects_;

};