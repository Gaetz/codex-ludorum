#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"
#include "Vaisseau.h"
#include <vector>

using namespace std;

class EtatJeu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;

private:
  Vaisseau vaisseau {
    Constantes::VAISSEAU_DEPART_X,
    Constantes::VAISSEAU_DEPART_Y,
    0
  };
  vector<Tir> tirs;
};

#endif