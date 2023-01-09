#include "Lander.h"
#include <math.h>

Lander::Lander(string cheminTextureP, float xP, float yP, bool centreP) :
    Sprite { cheminTextureP, xP, yP, -PI / 2.0f, centreP }
{

}

void Lander::update(float dt) {
    if (IsKeyDown(KEY_SPACE)) {
        vx += cos(rotation) * abs(PROPULSION) * dt;
        vy += sin(rotation) * abs(PROPULSION) * dt;
        flammeVisible = true;
    } else {
        flammeVisible = false;
    }

    if (IsKeyDown(KEY_A)) {
        rotation -= VITESSE_ROTATION * dt;
        if (rotation < 0.0f) {
            rotation = 2 * PI + rotation;
        }
    } else if (IsKeyDown(KEY_D)) {
        rotation += VITESSE_ROTATION * dt;
        if (rotation > 2 * PI) {
            rotation = rotation - 2 * PI;
        }
    }

    vy += GRAVITE * dt;
    x += vx * dt;
    y += vy * dt;

    flamme.x = x;
    flamme.y = y;
    flamme.rotation = rotation;
    flamme.visible = flammeVisible;
}

void Lander::load() {
    Sprite::load();
    flamme.load();
}

void Lander::draw() {
    Sprite::draw();
    flamme.draw();
}

void Lander::unload() {
    Sprite::unload();
    flamme.unload();
}
