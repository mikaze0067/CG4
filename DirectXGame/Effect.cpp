#include "Effect.h"
#include <algorithm>

using namespace KamataEngine;
using namespace MathUtility;


void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation) {
	assert(model);

	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	
}

void Effect::Update() {

	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンター7うぃ1フレーム分の秒数を進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}

