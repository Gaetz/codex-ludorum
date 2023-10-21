#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vaisseau.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Ennemi : public Vaisseau {
public:
  Ennemi(float xP, float yP, float rotationP);
  void update(float dt) override;
};

#endif