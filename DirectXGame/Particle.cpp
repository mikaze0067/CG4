#include "Particle.h"

using namespace KamataEngine;
using namespace MathUtility;


void Particle::Initialize(Model* model) {
	assert(model);

	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	//色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Particle::Update() {

	// 移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	//行列を定数バッファに転送
	worldTransform_.UpdateMatrix();

}

void Particle::Draw(Camera& camera) {
	//3Dモデルを描画
	model_->Draw(worldTransform_, camera,&objectColor_);
}
