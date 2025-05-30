#pragma once
#include <KamataEngine.h>


// エフェクト
class Effect {
public:
	// 初期化
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation);

	// 更新
	void Update();

	// 描画
	void Draw(KamataEngine::Camera& camera);

	// デスフラグのgetter
	bool IsFinished() { return isFinished_; }



private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;
	// 移動量
	KamataEngine::Vector3 velocity_;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間
	const float kDuration = 1.0f;
	// 終了フラグ
	bool isFinished_ = false;

	// スケール補間用
	KamataEngine::Vector3 startScale_; // 開始スケール
	KamataEngine::Vector3 targetScale_; // 最終スケール

	// 回転速度
	KamataEngine::Vector3 rotationSpeed_;

	// 開始色（個別）
	KamataEngine::Vector4 startColor_;
	// 透明
	KamataEngine::Vector4 endColor_ = {1, 1, 1, 0};

	KamataEngine::Vector3 Lerp(const KamataEngine::Vector3& start, const KamataEngine::Vector3& end, float t);

	KamataEngine::Vector4 LerpColor(const KamataEngine::Vector4& start, const KamataEngine::Vector4& end, float t);
};
