#include "Effect.h"


void Effect::Initialize(KamataEngine::Model* model) {
	assert(model);

	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Effect::Update() {
	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
	//色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}

