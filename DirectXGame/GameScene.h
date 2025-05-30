#pragma once
#include "KamataEngine.h"
#include "Effect.h"

// ゲームシーン
class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);

private:

	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// エフェクトの3Dモデルデータ
	KamataEngine::Model* modelEffect_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	//エフェクト
	std::list<Effect*> effects_;

};