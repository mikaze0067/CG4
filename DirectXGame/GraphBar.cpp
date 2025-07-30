#include "GraphBar.h"

using namespace KamataEngine;

GraphBar::GraphBar() {}

GraphBar::~GraphBar() {
	delete redBar_;
	delete greenBar_;
}

void GraphBar::Initialize(const Vector2& position, const Vector2& size) {
	position_ = position;
	fullSize_ = size;

	objectColor_.Initialize();

	textureHandle_ = TextureManager::Load("white.png");

	redBar_ = Sprite::Create(textureHandle_, position_);
	greenBar_ = Sprite::Create(textureHandle_, position_);

	redBar_->SetSize(fullSize_);
	greenBar_->SetSize(fullSize_);

	// 初期色設定（RGBA）
	color_ = Vector4(1.0f, 0.0f, 0.0f, 1.0f);   // 赤
	objectColor_.SetColor(color_);              // 色変更オブジェクトに色をセット
	redBar_->SetColor(objectColor_.GetColor()); // redBarに適用

	color_ = Vector4(0.0f, 1.0f, 0.0f, 0.8f); // 緑・少し透明
	objectColor_.SetColor(color_);
	greenBar_->SetColor(objectColor_.GetColor());
}

void GraphBar::Update(float hpRatio) {
	Vector2 hpSize = {fullSize_.x * hpRatio, fullSize_.y};
	greenBar_->SetSize(hpSize);
}

void GraphBar::Draw() {
	redBar_->SetPosition(position_);
	greenBar_->SetPosition(position_);

	redBar_->Draw();
	greenBar_->Draw();
}
