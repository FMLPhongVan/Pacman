#include "Object.h"
#include <iostream>
#include <cmath>

std::pair<int, int> nextTileID;

Object::Object(int tileX, int tileY, int velX, int velY) {
    this->tileX = tileX;
    this->tileY = tileY;
    if (velX != 0) this->velX = velX;
    if (velY != 0) this->velY = velY;

    this->scrPosX = tileX * 16;
    this->scrPosY = tileY * 16;
}

void Object::move() {
    scrPosX += velX;
    scrPosY += velY;

    if (scrPosX % 16 == 0) tileX = scrPosX / 16;
    else tileX = (scrPosX + 8) / 16;

    if (scrPosY % 16 == 0) tileY = scrPosY / 16;
    else tileY = (scrPosY + 8) / 16;
}