#include "Map.h"

Map::Map()
    : currentType_(1) {
    // 初期マップ: 横40マスを1~6で順番に割り振る
    for (int x = 0; x < MAP_WIDTH; x++) {
        map_[0][x] = (x % 6) + 1;
    }
}

void Map::update(const char* keys, const char* preKeys) {
    // スペースキーを押すたびに床の種類を進める
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        currentType_++;
        if (currentType_ > 6) {
            currentType_ = 1;
        }

        // 指定された種類の床を「落とす」＝0にする
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map_[0][x] == currentType_) {
                map_[0][x] = 0;
            }
        }
    }
}

void Map::Draw() {
    for (int x = 0; x < MAP_WIDTH; x++) {
        int type = map_[0][x];
        if (type != 0) {
            Novice::DrawBox(
                x * TILE_SIZE, 600,
                TILE_SIZE, TILE_SIZE,
                0.0f, GetFloorColor(type),
                kFillModeSolid
            );
        }
    }
}

unsigned int Map::GetFloorColor(int type) const {
    (void)type; // 使わないことを明示して警告C4100を回避
    return 0xFF0000FF; // 常に赤色
}

bool Map::isPlayerOnFallingFloor(int px, int py, int pw, int ph) const {
    int left = px - pw / 2;
    int right = px + pw / 2;
    int bottom = py + ph / 2;

    int tileX1 = left / TILE_SIZE;
    int tileX2 = right / TILE_SIZE;
    int tileY = (bottom - 600) / TILE_SIZE;

    for (int tx = tileX1; tx <= tileX2; tx++) {
        if (tileY >= 0 && tileY < MAP_HEIGHT &&
            tx >= 0 && tx < MAP_WIDTH) {
            if (map_[tileY][tx] == 0) {
                return true; // 足元が落ち床
            }
        }
    }
    return false;
}