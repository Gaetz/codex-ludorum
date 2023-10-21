#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Sprite.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Vaisseau : public Sprite {
public:
  Vaisseau(float xP, float yP, float rotationP);
  void update(float dt);

  float vx { 0.0f };
  float vy { 0.0f };
};

#endif