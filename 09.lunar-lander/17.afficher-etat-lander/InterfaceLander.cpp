#include "InterfaceLander.h"
#include "raylib.h"

InterfaceLander::InterfaceLander(int xP, int yP) :
    x { xP },
    y { yP }
{

}

void InterfaceLander::update(float dt) {

}

void InterfaceLander::draw() {
    DrawText(libelleVx.c_str(), x, y, 10, WHITE);
    DrawText(libelleVy.c_str(), x, y + SEPARATION_VERTICALE, 10, WHITE);
    DrawText(libelleRotation.c_str(), x, y + SEPARATION_VERTICALE * 2, 10, WHITE);
}