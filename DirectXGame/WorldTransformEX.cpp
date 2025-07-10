#include "WorldTransformEX.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

void WorldTransformEX::UpdateMatrix() {
	// World変換行列を計算し、matWorld_に格納する
	matWorld_ = MakeAffineMatrix();
	//定数バッファへ転送する
	TransferMatrix();
}

Matrix4x4 WorldTransformEX::MakeAffineMatrix() {
	//Scale Matrix
	Matrix4x4 matScale = MakeScaleMatrix(scale_);
	
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateXMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateXMatrix(rotation_.z);
	Matrix4x4 matRot = matRotZ * matRotX * matRotY;

	// TranslateMatrix
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);
	//worldMatrix
	Matrix4x4 matWorld = matScale * matRot * matTrans;

	return matWorld;
}
