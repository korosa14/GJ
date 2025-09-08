#include <Novice.h>
#include <windows.h>
#include "Player.h"
#include "Map.h"
#include"GameOver.h"

const char kWindowTitle[] = "4062_境界の崩壊";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	//モニター解像度を取得
	int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);

	Novice::Initialize(kWindowTitle, screenW, screenH, true);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Map map;
	Player player;
	GameOver gameOver;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (!gameOver.IsActive()) {
			player.update(keys);
			map.update(keys, preKeys);

			//ゲームオーバー判定
			if (map.isPlayerOnFallingFloor(
				player.getX(), player.getY(),
				player.getW(), player.getH())) {
					{
						gameOver.trigger();
						gameOver.draw();
					}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		map.Draw();
		player.draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
