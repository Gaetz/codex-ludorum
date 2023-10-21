#ifndef ENNEMI_H
#define ENNEMI_H

#include "Sprite.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Ennemi : public Sprite {
public:
  Ennemi(float xP, float yP, float rotationP);
  void update(float dt);

  float vx { 0.0f };
  float vy { 0.0f };
};

#endif