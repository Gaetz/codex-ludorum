#include "Ennemi.h"
#include <math.h>

Ennemi::Ennemi(float xP, float yP, float rotationP,
               CoteEcran entree, CoteEcran sortie,
              float dureePhasePrincipaleP) :
  Vaisseau { "images/ennemi.png", rotationP, entree, sortie,
              xP, yP, dureePhasePrincipaleP }
{
  vies = Constantes::ENNEMI_VIES;
}

void Ennemi::updatePhasePrincipale(float dt) {
  vx = Constantes::ENNEMI_VITESSE * cos(rotation);
  vy = Constantes::ENNEMI_VITESSE * sin(rotation);
  Vaisseau::updatePhasePrincipale(dt);
}
