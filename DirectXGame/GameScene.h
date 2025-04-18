#pragma once
#include "KamataEngine.h"
#include "Particle.h"

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

	//パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);

private:
	//パーティクルの3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;
	//カメラ
	KamataEngine::Camera camera_;
	// パーティクル
	std::list<Particle*> particles_;
	


};