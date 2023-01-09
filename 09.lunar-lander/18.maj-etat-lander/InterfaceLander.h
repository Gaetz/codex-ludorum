#ifndef INTERFACE_LANDER_H
#define INTERFACE_LANDER_H

#include <string>
#include "Lander.h"

using namespace std;

class InterfaceLander {
public:
    InterfaceLander(int xP, int yP, Lander& landerP);
    void update(float dt);
    void draw();

    const int SEPARATION_VERTICALE { 25 };
    
    int x { 0 };
    int y { 0 };
    string libelleVx { "vx : 0" };
    string libelleVy { "vy : 0" };
    string libelleRotation { "angle : 0" };
    Lander& lander;
};
#endif