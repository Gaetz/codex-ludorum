#include "Lander.h"

void Lander::load() {
    texture = LoadTexture("assets/images/lander.png");
    x = 800/2 - texture.width/2;
    y = 600/2 - texture.height/2;
}

void Lander::update() {
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