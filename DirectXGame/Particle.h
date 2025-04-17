#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

//パーティクル
class Particle {
public:
	// 初期化
	void Initialize(Model* model,Vector3 position, Vector3 velocity);

	// 更新
	void Update();

	// 描画
	void Draw(Camera& camera);

	//デスフラグのgetter
	bool IsFinished() { return isFinished_; }

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
	// 色変更オブジェクト
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;
	//移動量
	Vector3 velocity_;
	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間
	const float kDuration = 1.0f;

};
