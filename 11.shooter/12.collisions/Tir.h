#ifndef TIR_H
#define TIR_H

#include "Sprite.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Tir : public Sprite {
public:
  Tir(float xP, float yP, float rotationP = 0.0f, bool ennemiP = false);
  void update(float dt);

  bool ennemi { false };
};

#endif