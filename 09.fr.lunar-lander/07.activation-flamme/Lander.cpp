#include "Lander.h"

Lander::Lander(string cheminTextureP, float xP, float yP, string cheminTextureFlammeP) :
    cheminTexture { cheminTextureP },
    x { xP },
    y { yP },
    cheminTextureFlamme { cheminTextureFlammeP }
{
    
}

void Lander::load() {
    texture = LoadTexture(cheminTexture.c_str());
    textureFlamme = LoadTexture(cheminTextureFlamme.c_str());
}

void Lander::update() {
    if (IsKeyDown(KEY_SPACE)) {
        vy += PROPULSION;
        flammeVisible = true;
    } else {
        flammeVisible = false;
    }
    
    vy += GRAVITE;
    x += vx;
    y += vy;
}

void Lander::draw() {
    DrawTexture(texture, x, y, WHITE);
    if (flammeVisible) {
        DrawTexture(textureFlamme, x, y, WHITE);
    }
}

void Lander::unload() {
    UnloadTexture(texture);
    UnloadTexture(textureFlamme);
}