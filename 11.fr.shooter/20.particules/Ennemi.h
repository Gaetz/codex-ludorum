#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vaisseau.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Ennemi : public Vaisseau {
public:
  Ennemi(float xP, float yP, float rotationP,
        CoteEcran entree, CoteEcran sortie,
        float dureePhasePrincipaleP);
  void updatePhasePrincipale(float dt) override;
};

#endif