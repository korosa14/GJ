#include "GameOver.h"

GameOver::GameOver()
	:active_(false){ }

void GameOver::trigger() {
	active_ = true;
}

bool GameOver::IsActive()const {
	return active_;
}

void GameOver::draw() const {
	if (active_) {
		Novice::ScreenPrintf(540, 360, "GAME OVER");
	}
}