#pragma once
#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

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
	void ParticleBorn(Vector3 position);

private:
	//パーティクルの3Dモデルデータ
	Model* modelParticle_ = nullptr;
	//カメラ
	Camera camera_;
	// パーティクル
	std::list<Particle*> particles_;
	


};