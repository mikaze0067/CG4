#include "Score.h"

using namespace KamataEngine;

Score::Score() {}

Score::~Score() {
	for (int i = 0; i < kDigitCount; i++) {
		delete digits_[i];
	}
}

void Score::Initialize(const Vector2& position) {
	textureHandle_ = TextureManager::Load("number.png");
	position_ = position;

	for (int i = 0; i < kDigitCount; i++) {
		Vector2 offset = {digitSize_.x * i, 0};
		Vector2 pos = {position_.x + offset.x, position_.y + offset.y};
		digits_[i] = Sprite::Create(textureHandle_, pos);
		digits_[i]->SetSize(digitSize_);
	}

	SetScore(0);
}

void Score::Update() {}

void Score::Draw() {
	for (int i = 0; i < kDigitCount; i++) {
		digits_[i]->Draw();
	}
}

void Score::SetScore(int score) {
	currentScore_ = score;

	int number = score;
	int digit = 10000;

	for (int i = 0; i < kDigitCount; i++) {
		int nowNumber = number / digit;
		number %= digit;
		digit /= 10;

		// テクスチャの切り出し範囲を変更（1文字32pxずつ右にずらす）
		digits_[i]->SetTextureRect({nowNumber * digitSize_.x, 0}, digitSize_);
	}
}
