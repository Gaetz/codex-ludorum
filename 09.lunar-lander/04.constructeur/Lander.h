#ifndef LANDER_H
#define LANDER_H

#include "raylib.h"
#include <string>

using namespace std;

class Lander {
public:
    Lander(string cheminTextureP, float xP, float yP);
    void load();
    void update();
    void draw();
    void unload();

    const float GRAVITE { 0.2f };

    string cheminTexture { "" };
    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
    float vx { 0.0f };
    float vy { 0.0f };
};

#endif