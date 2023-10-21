#ifndef LANDER_H
#define LANDER_H

#include "raylib.h"

class Lander {
public:
    void load();
    void update();
    void draw();
    void unload();

    const float GRAVITE { 0.2f };

    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
    float vx { 0.0f };
    float vy { 0.0f };
};

#endif