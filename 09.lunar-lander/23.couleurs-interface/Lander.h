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
    void load() override;
    void draw() override;
    void unload() override;
    bool atterrissageOk();
    int rotationDegres360();
    void replacer();
    bool vxOk();
    bool vyOk();
    bool rotationOk();

    float vx { 0.0f };
    float vy { 0.0f };
    bool flammeVisible { false };
    Sprite flamme { "assets/images/landerFlamme.png", 0.0f, 0.0f, 0.0f, true };
    float xDepart { 0.0f };
    float yDepart { 0.0f };
};

#endif