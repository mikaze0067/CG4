#include "Effect.h"

using namespace KamataEngine;
using namespace MathUtility;


void Effect::Initialize(KamataEngine::Model* model, Vector3 position) {
	assert(model);

	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;
}

void Effect::Update() {
	worldTransform_.rotation_ += {0.0f, 0.1f, 0.0f};

	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
	//色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}

