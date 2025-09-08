#include "Player.h"
#include <dinput.h>

Player::Player()
	: x_(320),y_(360),size_(64),speed_(8){ }

void Player::update(const char* keys) {
	if (keys[DIK_A]) x_ -= speed_;
	if (keys[DIK_D]) x_ += speed_;
	if (keys[DIK_W]) y_ -= speed_;
	if (keys[DIK_S]) y_ += speed_;
}

void Player::draw() const {
	int half = size_ / 2;
	Novice::DrawBox(
		x_ - half,
		y_ - half,
		size_,
		size_,
		0.0f,
		0x66CCFFFF,
		kFillModeSolid
	);
}