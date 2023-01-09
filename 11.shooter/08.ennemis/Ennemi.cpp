#include "Ennemi.h"
#include <math.h>

Ennemi::Ennemi(float xP, float yP, float rotationP) :
  Sprite{ "images/ennemi.png", xP, yP, rotationP, true }
{

}

void Ennemi::update(float dt) {
  vx = Constantes::ENNEMI_VITESSE * cos(rotation);
  vy = Constantes::ENNEMI_VITESSE * sin(rotation);
  x += vx * dt;
  y += vy * dt;
}
