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
    string formaterVx(float vx);
    string formaterVy(float vy);
    string formaterRotation(int rotationDegres);
    void afficherTexteFin(int etat);
    void cacherTexteFin();

    int x { 0 };
    int y { 0 };
    string libelleVx { "vx : 0" };
    string libelleVy { "vy : 0" };
    string libelleRotation { "angle : 0" };
    Lander& lander;
    bool texteFinAffiche { false };
    string texteFin { "" };
    bool vxOk { false };
    bool vyOk { false };
    bool rotationOk { false };

};
#endif