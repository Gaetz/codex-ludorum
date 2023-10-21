#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"
#include <string>
#include "Constantes.h"

using namespace std;

class Joueur : public Vaisseau {
public:
  Joueur(float xP, float yP, CoteEcran entree, CoteEcran sortie);
  void load() override;
  void updatePhasePrincipale(float dt) override;
};

#endif