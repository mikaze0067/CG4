#pragma once
#include "KamataEngine.h"


class TitleScene {
public:

	TitleScene();

	~TitleScene();

	
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


	int frame = 0;
};
