#include "Vaisseau.h"

Vaisseau::Vaisseau(string cheminTextureP, float xP, float yP, float rotationP) :
  Sprite{ cheminTextureP, xP, yP, rotationP, true }
{

}

void Vaisseau::update(float dt) {
  x += vx * dt;
  y += vy * dt;
}

Tir Vaisseau::tirer() {
  Rectangle rect = getRectangle();
  Tir tir = Tir(rect.x + rect.width, y);
  tir.load();
  tir.x = tir.x + tir.getRectangle().width / 2;
  return tir;
}