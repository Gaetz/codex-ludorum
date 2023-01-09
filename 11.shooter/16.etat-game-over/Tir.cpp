#include "Tir.h"
#include <math.h>

Tir::Tir(float xP, float yP, float rotationP, bool ennemiP) :
  Sprite{ ennemiP ? "images/tirEnnemi.png" : "images/tirVaisseau.png",
          xP, yP, rotationP, true },
  ennemi { ennemiP}
{

}

void Tir::update(float dt) {
  x += cos(rotation) * Constantes::TIR_VITESSE * dt;
  y += sin(rotation) * Constantes::TIR_VITESSE * dt;
}