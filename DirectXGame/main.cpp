#include "GameScene.h"
#include "KamataEngine.h"
#include <Windows.h>
#include "BackGround.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_07_ササノ_ミカゼ_CG4");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Initialize();

	// ゲームシーンのインスタンス生成
	BackGround* backGround = new BackGround();
	// ゲームシーンの初期化
	backGround->Initialize();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}
		// ゲームシーンの更新
		gameScene->Update();

		backGround->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		gameScene->Draw();

		backGround->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;
	delete backGround;
	// nullptrの代入
	gameScene = nullptr;
	backGround = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
