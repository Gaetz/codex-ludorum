#include "Tir.h"

Tir::Tir(float xP, float yP) :
  Sprite{ "images/tirVaisseau.png", xP, yP, 0, true }
{

}

void Tir::update(float dt) {
  x += Constantes::TIR_VITESSE * dt;
}