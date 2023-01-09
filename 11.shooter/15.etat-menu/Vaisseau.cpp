#include "Vaisseau.h"

Vaisseau::Vaisseau(string cheminTextureP, float xP, float yP, float rotationP) :
  Sprite{ cheminTextureP, xP, yP, rotationP, true }
{

}

void Vaisseau::update(float dt) {
  x += vx * dt;
  y += vy * dt;
}

Tir Vaisseau::tirer(float rotation, bool ennemi) {
  Rectangle rect = getRectangle();
  float xTir = ennemi ? rect.x : rect.x + rect.width;
  Tir tir = Tir(xTir, y, rotation, ennemi);
  tir.load();
  tir.x = tir.x + tir.getRectangle().width / 2;
  return tir;
}

bool Vaisseau::degats(int nbDegats) {
	vies -= nbDegats;
	if (vies <= 0) {
		return true;
	}
	return false;
}