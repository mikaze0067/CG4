#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
	delete sprite_;
}

void TitleScene::Initialize() {

	textureHandle_ = TextureManager::Load("game.png");
	textureHandle2_ = TextureManager::Load("title.png");

	input_ = Input::GetInstance();
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
	sprite2_ = Sprite::Create(textureHandle2_, {0, 0});

	finished_ = false;
}

void TitleScene::Update() {
	frame++;
	float y = 45 * sin(frame * 0.05f);

	sprite_->SetPosition({0.0f, y});

	if (input_->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}
}

void TitleScene::Draw() {

	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// 描画
	sprite2_->Draw();

	sprite_->Draw();

	// 3Dモデル描画後処理
	Sprite::PostDraw();
}
