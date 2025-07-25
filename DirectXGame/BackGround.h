#pragma once
#include "KamataEngine.h"


class BackGround {
public:
	BackGround();

	~BackGround();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* sprite2_ = nullptr;

	float scrollX_ = 0.0f;
	const float scrollSpeed_ = 2.0f; // 任意で調整
	const float screenWidth_ = 1280.0f;
};
