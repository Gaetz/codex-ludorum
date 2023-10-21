#include "InterfaceLander.h"
#include "raylib.h"
#include <math.h>
#include "Constantes.h"

InterfaceLander::InterfaceLander(int xP, int yP, Lander& landerP) :
    x { xP },
    y { yP },
    lander { landerP }
{

}

void InterfaceLander::update(float dt) {
    libelleVx = formaterVx(lander.vx);
    libelleVy = formaterVy(lander.vy);
    libelleRotation = formaterRotation(lander.rotationDegres360());
}

void InterfaceLander::draw() {
    DrawText(libelleVx.c_str(), x, y, 10, WHITE);
    DrawText(libelleVy.c_str(), x, y + Constantes::SEPARATION_VERTICALE, 10, WHITE);
    DrawText(libelleRotation.c_str(), x, y + Constantes::SEPARATION_VERTICALE * 2, 10, WHITE);
}

string InterfaceLander::formaterVx(float vx) {
    string valeurVx { "" };
    if (vx < 0.0f) {
        valeurVx = to_string(vx).substr(0, 6);
    } else {
        valeurVx = to_string(vx).substr(0, 5);
    }
    string texteVx = "vx : " + valeurVx;
    return texteVx;
}

string InterfaceLander::formaterVy(float vy) {
    string valeurVy { "" };
    if (vy < 0.0f) {
        valeurVy = to_string(vy).substr(0, 6);
    } else {
        valeurVy = to_string(vy).substr(0, 5);
    }
    string texteVy = "vy : " + valeurVy;
    return texteVy;
}

string InterfaceLander::formaterRotation(int rotationDegres) {
    string texteRotation = "rotation : " + to_string(rotationDegres);
    return texteRotation;
}
