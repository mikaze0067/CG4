#include "BackGround.h"

using namespace KamataEngine;

BackGround::BackGround() {}

BackGround::~BackGround() {
	delete sprite_;
	delete sprite2_;
}

void BackGround::Initialize() {
	textureHandle_ = TextureManager::Load("BG.png");

	sprite_ = Sprite::Create(textureHandle_, {0, 0});
	sprite2_ = Sprite::Create(textureHandle_, {0, 0}); // 同じ画像を使用
}

void BackGround::Update() {
	// 左に移動（x値をマイナス）
	scrollX_ -= scrollSpeed_;

	// -1280 より小さくなったら +1280 してループ
	if (scrollX_ <= -screenWidth_) {
		scrollX_ += screenWidth_;
	}
}

void BackGround::Draw() {
	// 描画位置の設定と描画処理
	sprite_->SetPosition({scrollX_, 0});
	sprite_->Draw();

	sprite2_->SetPosition({scrollX_ + screenWidth_, 0});
	sprite2_->Draw();
}
