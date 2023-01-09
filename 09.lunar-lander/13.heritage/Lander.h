#ifndef LANDER_H
#define LANDER_H

#include "raylib.h"
#include <string>

#include "Sprite.h"

using namespace std;

class Lander : public Sprite {
public:
    Lander(string cheminTextureP, float xP, float yP, bool centreP);
    void update(float dt);
    
    const float GRAVITE { 100.0f };
    const float PROPULSION { -180.0f };
    const float VITESSE_ROTATION { 2.0f };

    float vx { 0.0f };
    float vy { 0.0f };
    bool flammeVisible { false };
};

#endif