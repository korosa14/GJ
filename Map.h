#pragma once
#include <Novice.h>


//マップの横幅と縦幅
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 20;
const int TILE_SIZE = 64;

//マップチップの種類
enum TileType {
	TILE_NONE = 0,
	TILE_RED,    //1
	TILE_GREEN,  //2
	TILE_BLUE,   //3
	TILE_YELLOW, //4
	TILE_MAGENTA,//5
	TILE_CYAN,   //6
};

class Map {
public:
	Map();

	void update();
	void Draw();

	//プレイヤーが落ち床にいるか判定
	bool isPlayerOnFallingFloor(int px, int py, int pw, int ph)const;

	//制限時間を取得
	int getTime() const { return limitTime_ / 60; }

private:
	int map_[MAP_HEIGHT][MAP_WIDTH];
	int currentType_;

	//制限時間
	int limitTime_;
	int frameCount_;

	unsigned int GetFloorColor(int type)const;
	void DrawTile(int x, int y, int type)const;
};

