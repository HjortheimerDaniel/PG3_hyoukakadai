#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "GC2A_05_ジュットハイマー_ダニエル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	GameManager* gameManager = new GameManager();

	gameManager->Run(keys, preKeys);

	delete gameManager;

	Novice::Finalize();
	return 0;
}
