#ifndef TILE_H
#define TILE_H

#include "Sprite.h"
#include <string>

using namespace std;

class Tile : public Sprite {
public:
    Tile(string cheminTextureP, int xCarteP, int yCarteP, bool passableP);
    int xCarte { 0 };
    int yCarte { 0 };
    bool passable { true };
};

#endif