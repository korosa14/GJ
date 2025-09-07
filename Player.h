#pragma once
#include <Novice.h>

class Player {
public:
	Player();

	void update(const char* keys);
	void draw() const;

	//中央座標を取得
	int getX() const { return x_; }
	int getY() const { return y_; }
	//サイズを取得
	int getW() const { return size_; }
	int getH() const { return size_; }

private:
	int x_;
	int y_;
	int size_;
	int speed_;
};
