#include "Player.h"

Player::Player()
:pos(320,240),speed(280.0f),width(32.0f),height(32.0f){ }

Vecotr2 Player::normalize(const Vecotr2& v) const {
	float len = std::sqrt(v.x * v.x + v.y * v.y);
	if (len > 1e-6f) {
		return { v.x / len,v.y / len };
	}
	return{ 0,0 };
}

void Player::update(float dt, int screenW, int screenH, const char* keys) {
	//移動ベクトル
	Vecotr2 dir(0, 0);

	if (keys[DIK_A]) dir.x -= 1;
	if (keys[DIK_D]) dir.x += 1;
	if (keys[DIK_W]) dir.y -= 1;
	if (keys[DIK_S]) dir.y += 1;

	dir = normalize(dir);

	pos.x += dir.x * speed * dt;
	pos.y += dir.y * speed * dt;

	float halfW = width / 2;
	float halfH = height / 2;

	if (pos.x < halfW)pos.x = halfW;
	if (pos.x > screenW - halfW)pos.x = screenW - halfW;
	if (pos.y < halfH)pos.y = halfH;
	if (pos.y > screenH - halfH)pos.y = screenH - halfH;
}

void Player::draw() const {
	float halfW = width / 2;
	float halfH = height / 2;
	Novice::DrawBox(
		static_cast<int>(pos.x - halfW),
		static_cast<int>(pos.y - halfH),
		static_cast<int>(width),
		static_cast<int>(height),
		0.0f,
		0x66CCFFFF,
		kFillModeSolid
	);
}