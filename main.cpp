#include <Novice.h>
#include "Player.h"
#include "Map.h"
#include"GameOver.h"

const char kWindowTitle[] = "4062_境界の崩壊";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	/*
	int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);
	*/

	Novice::Initialize(kWindowTitle, 1280, 720);


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Map map;
	Player player;
	GameOver gameOver;
	
	int scene = 0;

	int title = Novice::LoadTexture("title.png");
	int gameover = Novice::LoadTexture("gameover.png");

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
		
		switch (scene)
		{
		case 0:
			if (keys[DIK_P]&&preKeys[DIK_P]==0)
			{
				scene = 1;
			}
			break;
		case 1:
			if (!gameOver.IsActive()) {
				player.update(keys);
				map.update(keys, preKeys);

				//ゲームオーバー判定
				if (map.isPlayerOnFallingFloor(
					player.getX(), player.getY(),
					player.getW(), player.getH())) {
						{
							gameOver.trigger();
							scene = 2;
						}
				}
			}
			break;
		case 2:
			if (keys[DIK_P] && preKeys[DIK_P] == 0)
			{
				scene = 0;
			}
			break;
		}
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene)
		{
		case 0:
			Novice::DrawSprite(0, 0, title, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			break;
		case 1:
			map.Draw();
			player.draw();
			break;
		case 2:
			Novice::DrawSprite(0, 0, gameover, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			break;
		}



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
