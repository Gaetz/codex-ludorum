#ifndef TIR_H
#define TIR_H

#include "Sprite.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Tir : public Sprite {
public:
  Tir(float xP, float yP);
  void update(float dt);
};

#endif