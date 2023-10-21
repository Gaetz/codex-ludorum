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
    
    if (IsKeyDown(KEY_A)) {
        rotation -= VITESSE_ROTATION;
    } else if (IsKeyDown(KEY_D)) {
        rotation += VITESSE_ROTATION;
    }
    
    vy += GRAVITE;
    x += vx;
    y += vy;
}

void Lander::draw() { 
    DrawTextureEx(texture, Vector2 { x, y }, rotation, 1.0f, WHITE);
    if (flammeVisible) {
        DrawTextureEx(textureFlamme, Vector2 { x, y }, rotation, 1.0f, WHITE);
    }
}

void Lander::unload() {
    UnloadTexture(texture);
    UnloadTexture(textureFlamme);
}