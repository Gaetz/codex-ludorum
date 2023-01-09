#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Sprite.h"
#include <string>

using namespace std;

class Vaisseau : public Sprite {
public:
  Vaisseau(float xP, float yP, float rotationP);
  void update(float dt);
};

#endif