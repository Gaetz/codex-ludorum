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
    origine = { (float) (texture.width / 2), (float) (texture.height / 2) };
    srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
}

void Lander::update(float dt) {
    if (IsKeyDown(KEY_SPACE)) {
        vy += PROPULSION * dt;
        flammeVisible = true;
    } else {
        flammeVisible = false;
    }
    
    if (IsKeyDown(KEY_A)) {
        rotation -= VITESSE_ROTATION * dt;
    } else if (IsKeyDown(KEY_D)) {
        rotation += VITESSE_ROTATION * dt;
    }
    
    vy += GRAVITE * dt;
    x += vx * dt;
    y += vy * dt;
}

void Lander::draw() { 
    dstRect = { x, y, (float)texture.width, (float)texture.height};
    DrawTexturePro(texture, srcRect, dstRect, origine, rotation, WHITE);
    if (flammeVisible) {
        DrawTexturePro(textureFlamme, srcRect, dstRect, origine, rotation, WHITE);
    }
}

void Lander::unload() {
    UnloadTexture(texture);
    UnloadTexture(textureFlamme);
}