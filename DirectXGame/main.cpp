#include "KamataEngine.h"
#include <Windows.h>
#include "GameScene.h"
#include "TitleScene.h"

using namespace KamataEngine;

TitleScene* titleScene = nullptr;

// シーン（型）
enum class Scene {
	kTitle,
	kGame,
};

// 現在シーン（型）
Scene scene = Scene::kTitle;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_07_ササノ_ミカゼ_CG4");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 最初のシーンの初期化
	scene = Scene::kTitle;
	// タイトルシーンの初期化
	titleScene = new TitleScene();
	titleScene->Initialize();

	GameScene* gameScene = nullptr;


	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		switch (scene) {
		case Scene::kTitle:
			titleScene->Update();
			if (titleScene->IsFinished()) {
				// ゲームシーンのインスタンス生成
				gameScene = new GameScene();
				// ゲームシーンの初期化
				gameScene->Initialize();
				scene = Scene::kGame;
			}
			break;

		case Scene::kGame:
			gameScene->Update();
			break;
		}

		// 描画開始
		dxCommon->PreDraw();

		switch (scene) {
		case Scene::kTitle:
			titleScene->Draw();
			break;
		case Scene::kGame:
			// ゲームシーンの描画
			gameScene->Draw();
			break;
		}

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;
	delete titleScene;
	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
