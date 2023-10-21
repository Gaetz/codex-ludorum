#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Joueur : public Vaisseau {
public:
  Joueur(float xP, float yP);
  void update(float dt) override;
};

#endif