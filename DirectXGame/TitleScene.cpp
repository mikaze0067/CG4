#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
	delete sprite_;
}

void TitleScene::Initialize() {

	textureHandle_ = TextureManager::Load("game.png");

	sprite_ = Sprite::Create(textureHandle_, {0, 0});

}

void TitleScene::Update() {
	frame++;
	float y = 45 * sin(frame * 0.05f);

	sprite_->SetPosition({0.0f, y});
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
