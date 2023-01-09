#include "Ennemi.h"
#include <math.h>

Ennemi::Ennemi(float xP, float yP, float rotationP) :
  Vaisseau { "images/ennemi.png", xP, yP, rotationP }
{

}

void Ennemi::update(float dt) {
  vx = Constantes::ENNEMI_VITESSE * cos(rotation);
  vy = Constantes::ENNEMI_VITESSE * sin(rotation);
  Vaisseau::update(dt);
}
