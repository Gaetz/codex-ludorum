#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include <string>

using namespace std;

class Sprite {
public:
    Sprite(string cheminTextureP, float xP, float yP, float rotationP, bool centreP);
    virtual void load();
    virtual void draw();
    virtual void unload();

    string cheminTexture { "" };
    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
    float rotation { 0.0f };
    Vector2 origine { 0.0f, 0.0f };
    Rectangle srcRect { 0.0f, 0.0f, 0.0f, 0.0f };
    Rectangle dstRect { 0.0f, 0.0f, 0.0f, 0.0f };
    bool visible { true };
    bool centre { false };
};

#endif