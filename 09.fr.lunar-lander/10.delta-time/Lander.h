#ifndef LANDER_H
#define LANDER_H

#include "raylib.h"
#include <string>

using namespace std;

class Lander {
public:
    Lander(string cheminTextureP, float xP, float yP, string cheminTextureFlamme);
    void load();
    void update(float dt);
    void draw();
    void unload();
    
    const float GRAVITE { 100.0f };
    const float PROPULSION { -180.0f };
    const float VITESSE_ROTATION { 2.0f };

    string cheminTexture { "" };
    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
    float vx { 0.0f };
    float vy { 0.0f };
    string cheminTextureFlamme { "" };
    Texture2D textureFlamme;
    bool flammeVisible { false };
    float rotation { 0.0f };
    Vector2 origine { 0.0f, 0.0f };
    Rectangle srcRect { 0.0f, 0.0f, 0.0f, 0.0f };
    Rectangle dstRect { 0.0f, 0.0f, 0.0f, 0.0f };
};

#endif