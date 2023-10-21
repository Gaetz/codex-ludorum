#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Sprite.h"
#include <string>
#include "Constantes.h"
#include "Tir.h"

using namespace std;

class Vaisseau : public Sprite {
public:
  Vaisseau(string cheminTextureP, float xP, float yP, float rotationP);
  virtual void update(float dt);
  Tir tirer(float rotation = 0.0f, bool ennemi = false);
  bool degats(int nbDegats);

  float vx { 0.0f };
  float vy { 0.0f };
  int vies { 1 };
};

#endif