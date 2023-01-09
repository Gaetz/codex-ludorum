#include "Lander.h"

Lander::Lander(string cheminTextureP, float xP, float yP) :
    cheminTexture { cheminTextureP },
    x { xP },
    y { yP }
{
    
}

void Lander::load() {
    texture = LoadTexture(cheminTexture.c_str());
}

void Lander::update() {
    if (IsKeyDown(KEY_SPACE)) {
        vy += PROPULSION;
    }
    
    vy += GRAVITE;
    x += vx;
    y += vy;
}

void Lander::draw() {
    DrawTexture(texture, x, y, WHITE);
}

void Lander::unload() {
    UnloadTexture(texture);
}