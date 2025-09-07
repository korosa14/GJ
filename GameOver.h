#pragma once
#include <Novice.h>
#include <string>

class GameOver {
public:
	GameOver();

	//ゲームオーバー処理
	void trigger();
	
	//ゲームオーバー中かどうか
	bool IsActive() const;

	//描画処理
	void draw() const;

private:
	//ゲームオーバーフラグ
	bool active_;
};
