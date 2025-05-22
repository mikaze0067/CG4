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

	// エフェクトの3Dモデルデータ
	Model* modelEffect_ = nullptr;
	// カメラ
	Camera camera_;
	//エフェクト
	Effect* effect_ = nullptr;

};