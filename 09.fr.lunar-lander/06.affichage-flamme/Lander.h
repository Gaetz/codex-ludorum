#ifndef LANDER_H
#define LANDER_H

#include "raylib.h"
#include <string>

using namespace std;

class Lander {
public:
    Lander(string cheminTextureP, float xP, float yP, string cheminTextureFlamme);
    void load();
    void update();
    void draw();
    void unload();
    
    const float GRAVITE { 0.2f };
    const float PROPULSION { -0.3f };

    string cheminTexture { "" };
    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
    float vx { 0.0f };
    float vy { 0.0f };
    string cheminTextureFlamme { "" };
    Texture2D textureFlamme;
};

#endif