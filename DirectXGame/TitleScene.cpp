#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { delete sprite_; }

void TitleScene::Initialize() {

	textureHandle_ = TextureManager::Load("White.png");

	sprite_ = Sprite::Create(textureHandle_, {0, 0});

}

void TitleScene::Update() {


}

void TitleScene::Draw() {

	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());
	// 描画
	sprite_->Draw();

	// 3Dモデル描画後処理
	Sprite::PostDraw();
}
