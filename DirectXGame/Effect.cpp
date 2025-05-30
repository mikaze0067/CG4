#include "Effect.h"
#include <algorithm>
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model, Vector3 position, Vector3 scale, Vector3 rotation) {
	assert(model);

	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	startScale_ = scale * 0.1f;
	targetScale_ = scale;
	worldTransform_.scale_ = startScale_;
	worldTransform_.rotation_ = rotation;

	 objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
	objectColor_.SetColor(color_);

	counter_ = 0.0f;
	isFinished_ = false;

	// 回転速度
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
	rotationSpeed_ = {dist(gen) * 3.0f, dist(gen) * 3.0f, dist(gen) * 3.0f}; // 各軸ごと
}

void Effect::Update() {
	if (isFinished_)
		return;

	counter_ += 1.0f / 60.0f;
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}

	// 寿命の進行度
	float progress = counter_ / kDuration;

	// スケール補間
	worldTransform_.scale_ = Lerp(startScale_, targetScale_, progress);

	// 透明度フェード
	//color_.w = std::clamp(1.0f - progress, 0.0f, 1.0f);

	worldTransform_.rotation_ += rotationSpeed_ * (1.0f / 60.0f);

	 // 色変化 (赤→黄→透明)
	Vector4 startColor = {1, 0, 0, 1};  // 赤
	Vector4 middleColor = {1, 1, 0, 1}; // 黄
	Vector4 endColor = {1, 1, 0, 0};    // 黄 + 透明

	if (progress < 0.7f) {
		// 赤→白
		color_ = LerpColor(startColor, middleColor, progress / 0.7f);
	} else {
		// 白→透明
		color_ = LerpColor(middleColor, endColor, (progress - 0.7f) / 0.3f);
	}

	worldTransform_.UpdateMatrix();
	objectColor_.SetColor(color_);
}

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }

Vector3 Effect::Lerp(const Vector3& start, const Vector3& end, float t) { return start + (end - start) * t; }

Vector4 Effect::LerpColor(const Vector4& start, const Vector4& end, float t) {
	Vector4 result;
	result.x = start.x + (end.x - start.x) * t;
	result.y = start.y + (end.y - start.y) * t;
	result.z = start.z + (end.z - start.z) * t;
	result.w = start.w + (end.w - start.w) * t;
	return result;
}
