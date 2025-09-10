#include <Novice.h>
#include "Player.h"
#include "Map.h"
#include"GameOver.h"
#include <windows.h>

const char kWindowTitle[] = "4062_境界の崩壊";

//シーン
enum Scene {
	TITLE,
	INSTRUCTION,
	PLAY,
	GAMEOVER,
	GAMECLEAR,
};

Scene scene = TITLE;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {


	Novice::Initialize(kWindowTitle, 1280, 720, true);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Map map;
	Player player;
	GameOver gameOver;

	//画像読み込み
	/*int titleTex = Novice::LoadTexture("title.png");
	int instructionTex = Novice::LoadTexture("instruction.png");
	int gameOverTex = Novice::LoadTexture("gameover.png");
	int gameClearTex = Novice::LoadTexture("gameclear.png");*/

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
		
		//ループ
		switch (scene) {
			case TITLE:
				if (preKeys[DIK_P] == 0 && keys[DIK_P] != 0) {
					scene = INSTRUCTION;
				}
				Novice::ScreenPrintf(540, 360, "TITLE(Press P)");
				//Novice::DrawSprite(0, 0, titleTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFF);
				break;

			case INSTRUCTION:
				if (preKeys[DIK_P] == 0 && keys[DIK_P] != 0) {
					map = Map();
					player = Player();
					gameOver = GameOver();
					scene = PLAY;
				}
				Novice::ScreenPrintf(540, 360, "INSTRUCTION(Press P)");
				//Novice::DrawSprite(0, 0, instructionTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				break;

			case PLAY:
				if (!gameOver.IsActive()) {
					map.update();
					player.update(keys);

					if (map.getTime() <= 0) {
						scene = GAMECLEAR;
					}
					else if (map.isPlayerOnFallingFloor(player.getX(), player.getY(),
						player.getW(), player.getH())){
						gameOver.trigger();
						scene = GAMEOVER;
					}

				}
				map.Draw();
				player.draw();
				break;

			case GAMEOVER:
				if (preKeys[DIK_P] == 0 && keys[DIK_P] != 0) {
					scene = TITLE;
				}
				gameOver.draw();
				Novice::ScreenPrintf(540, 360, "GAME OVER(Press P)");
				//Novice::DrawSprite(0, 0, gameOverTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				break;

			case GAMECLEAR:
				if (preKeys[DIK_P] == 0 && keys[DIK_P] != 0) {
					scene = TITLE;
				}
				Novice::ScreenPrintf(540, 360, "GAME CLEAR(Press P)");
				//Novice::DrawSprite(0, 0, gameClearTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				break;
		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		//Novice::DrawSprite(0,0, title,1.0f,1.0f,0.0f,0xFFFFFFFF);
		

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
