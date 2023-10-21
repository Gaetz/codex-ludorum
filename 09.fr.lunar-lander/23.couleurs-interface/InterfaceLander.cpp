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
    vxOk = lander.vxOk();
    vyOk = lander.vyOk();
    rotationOk = lander.rotationOk();

    libelleVx = formaterVx(lander.vx);
    libelleVy = formaterVy(lander.vy);
    libelleRotation = formaterRotation(lander.rotationDegres360());
}

void InterfaceLander::draw() {
    /*
    Color couleurVx;
    if(vxOk) {
        couleurVx = WHITE;
    } else {
        couleurVx = RED;
    }

    Color couleurVy;
    if(vyOk) {
        couleurVy = WHITE;
    } else {
        couleurVy = RED;
    }

    Color couleurRotation;
    if(rotationOk) {
        couleurRotation = WHITE;
    } else {
        couleurRotation = RED;
    }
    */

    Color couleurVx = vxOk ? WHITE : RED;
    Color couleurVy = vyOk ? WHITE : RED;
    Color couleurRotation = rotationOk ? WHITE : RED;

    DrawText(libelleVx.c_str(), x, y, 10, couleurVx);
    DrawText(libelleVy.c_str(), x, y + Constantes::SEPARATION_VERTICALE, 10, couleurVy);
    DrawText(libelleRotation.c_str(), x, y + Constantes::SEPARATION_VERTICALE * 2, 10, couleurRotation);
    if (texteFinAffiche) {
        DrawText(texteFin.c_str(), x + Constantes::X_TEXTE_FIN, y + Constantes::Y_TEXTE_FIN, 20, WHITE);
    }
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

void InterfaceLander::afficherTexteFin(int etat) {
    if (etat == 1) {
        texteFin = "Atterrissage parfait\nR pour relancer";
    } else if (etat == 2) {
        texteFin = "Lander détruit\nR pour relancer";
    }
    texteFinAffiche = true;
}

void InterfaceLander::cacherTexteFin() {
    texteFinAffiche = false;
}