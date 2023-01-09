#ifndef MONTAGNES_H
#define MONTAGNES_H

#include "Ligne.h"
#include <vector>

using namespace std;

class Montagnes
{
public:
    Montagnes(float siteX, float siteY);
    void tracerLignes(float siteX, float siteY);
    void ajouterLigne(Vector2 debut, Vector2 fin);
    void effacerLignes();
    void draw();

    vector<Ligne> lignes;
};

#endif