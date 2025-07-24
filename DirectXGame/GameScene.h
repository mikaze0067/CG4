#pragma once
#include "KamataEngine.h"
#include "BackGround.h"


// ゲームシーン
class GameScene {
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	BackGround* backGround = nullptr;

};