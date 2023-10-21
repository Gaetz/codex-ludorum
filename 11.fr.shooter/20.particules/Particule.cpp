#include "Particule.h"
#include <math.h>

Particule::Particule(float xP, float yP, Color couleurP):
  x { xP }, y { yP }, couleur { couleurP }
{

}

void Particule::update() {
  x = x + vx;
  y = y + vy;
  if (GetRandomValue(0, 100) < 30) {
    taille = max(taille - 1.0f, 0.0f);
  }
}

void Particule::draw() {
  DrawRectangle(x, y, taille, taille, couleur);
}