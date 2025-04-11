#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

//パーティクル
class Particle {
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
};
