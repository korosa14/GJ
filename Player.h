#pragma once
#include <Novice.h>
#include <cmath>
#include <algorithm>

//2次元ベクトル
struct Vecotr2 {
	float x = 0.0f;
	float y = 0.0f;
	Vecotr2() = default;
	Vecotr2(float X, float Y) : x(X), y(Y){}
};

//プレイヤークラス
class Player {
public:
	Player();

	//更新処理
	void update(float dt, int screenW, int screenH, const char* keys);

	//描画処理
	void draw() const;

private:
	Vecotr2 pos;
	float speed;
	float width;
	float height;

	Vecotr2 normalize(const Vecotr2& v) const;
};
