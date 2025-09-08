#include <Novice.h>
#include "Player.h"
#include "Map.h"
#include"GameOver.h"

const char kWindowTitle[] = "4062_境界の崩壊";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {


	Novice::Initialize(kWindowTitle, 1280, 720, true);

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
		//int title = Novice::LoadTexture("title.png");
		
		if (!gameOver.IsActive()) {
			map.update();
			player.update(keys);

			if (map.isPlayerOnFallingFloor(player.getX(), player.getY(),
				player.getW(), player.getH())) {
				gameOver.trigger();
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		//Novice::DrawSprite(0,0, title,1.0f,1.0f,0.0f,0xFFFFFFFF);
		map.Draw();
		player.draw();
		gameOver.draw();

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
