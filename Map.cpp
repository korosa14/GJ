#include "Map.h"
#include <cstdlib>
#include<cstdio>

//初期マップ
int initMap[MAP_HEIGHT][MAP_WIDTH] =
{
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
    {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6},
};

Map::Map()
    : currentType_(1), limitTime_(50*60),frameCount_(0) {
    //初期マップをコピー
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map_[y][x] = initMap[y][x];
        }
    }
}

void Map::update() {
    if (limitTime_ > 0) {
        limitTime_--;
        frameCount_++;


        //10秒毎にランダムで1~5を落下
        if (frameCount_ >= 600) {
            frameCount_ = 0;
            currentType_ = 1 + rand() % 5;

            for (int y = 0; y < MAP_HEIGHT; y++) {
                for (int x = 0; x < MAP_WIDTH; x++) {
                    if (map_[y][x] == currentType_) {
                        map_[y][x] = TILE_NONE;
                    }
                }
            }
        }
    }
}

void Map::Draw() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int type = map_[y][x];
            if (type != TILE_NONE) {
                DrawTile(x, y, type);
            }
        }
    }

    //残り時間を画面に表示
    char buffer[64];
    sprintf_s(buffer,sizeof(buffer), "TIME: %d", limitTime_ / 60);
    Novice::ScreenPrintf(10, 10, buffer);

}

void Map::DrawTile(int x, int y, int type)const {
    Novice::DrawBox(
        x * TILE_SIZE, y * TILE_SIZE,
        TILE_SIZE, TILE_SIZE,
        0.0f, GetFloorColor(type),
        kFillModeSolid
    );
}

unsigned int Map::GetFloorColor(int type) const {
    switch (type)
    {
    case TILE_RED: return 0xFF0000FF; // 赤
    case TILE_GREEN: return 0x00FF00FF; // 緑
    case TILE_BLUE: return 0x0000FFFF; // 青
    case TILE_YELLOW: return 0xFFFF00FF; // 黄
    case TILE_MAGENTA: return 0xFF00FFFF; // マゼンタ
    case TILE_CYAN: return 0x00FFFFFF; // シアン
    default:        return 0x000000FF; // 黒（エラー用）
    }
}

bool Map::isPlayerOnFallingFloor(int px, int py, int pw, int ph) const {
    int left = px - pw / 2;
    int right = px + pw / 2;
    int top = py - ph / 2;
    int bottom = py + ph / 2;

    int tileX1 = left / TILE_SIZE;
    int tileX2 = right / TILE_SIZE;
    int tileY1 = top / TILE_SIZE;
    int tileY2 = bottom / TILE_SIZE;

    for (int ty = tileY1; ty <= tileY2; ty++) {
        for (int tx = tileX1; tx <= tileX2; tx++) {
            if (ty >= 0 && ty < MAP_HEIGHT &&
                tx >= 0 && tx < MAP_WIDTH) {
                if (map_[ty][tx] == TILE_NONE) {
                    return true;
                }
            }
        }
    }
    return false;
}