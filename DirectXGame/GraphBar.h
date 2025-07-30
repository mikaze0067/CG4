#pragma once
#include <KamataEngine.h>

class GraphBar {
public:
	GraphBar();
	~GraphBar();

	// 初期化（座標とサイズを設定できるように拡張）
	void Initialize(const KamataEngine::Vector2& position, const KamataEngine::Vector2& size);

	// 更新（hp比率 0.0〜1.0）
	void Update(float hpRatio);

	// 描画
	void Draw();

private:
	KamataEngine::Sprite* redBar_ = nullptr;
	KamataEngine::Sprite* greenBar_ = nullptr;

	int textureHandle_ = -1;

	KamataEngine::Vector2 position_;
	KamataEngine::Vector2 fullSize_;

	KamataEngine::ObjectColor objectColor_;
	KamataEngine::Vector4 color_;


};
