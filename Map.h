#pragma once
#include <Novice.h>

//マップの横幅と縦幅
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 1;
const int TILE_SIZE = 64;

class Map {
public:
	Map();

	void update(const char* keys, const char* preKeys);
	void Draw();

	//プレイヤーが落ち床にいるか判定
	bool isPlayerOnFallingFloor(int px, int py, int pw, int ph)const;

	//指定座標のマップ値を取得
	int GetTile(int y, int x)const { return map_[y][x]; }

private:
	int map_[MAP_HEIGHT][MAP_WIDTH];//マップデータ
	int currentType_;
	unsigned int GetFloorColor(int type)const;
};

