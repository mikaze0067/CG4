#pragma once
#include <KamataEngine.h>

class Score {
public:
	Score();
	~Score();

	// 初期化（描画位置とテクスチャ）
	void Initialize(const KamataEngine::Vector2& position);

	// 更新
	void Update();

	// 描画
	void Draw();

	// スコアの設定
	void SetScore(int score);

private:
	static const int kDigitCount = 5;
	KamataEngine::Sprite* digits_[kDigitCount] = {};
	int textureHandle_ = -1;

	KamataEngine::Vector2 position_;
	KamataEngine::Vector2 digitSize_ = {32.0f, 64.0f};

	int currentScore_ = 0;
};