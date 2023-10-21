#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"
#include <vector>
#include "Ennemi.h"
#include "Joueur.h"

using namespace std;

class EtatJeu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;

private:
  Joueur joueur {
    Constantes::VAISSEAU_DEPART_X,
    Constantes::VAISSEAU_DEPART_Y
  };

  vector<Tir> tirs;
  vector<Ennemi> ennemis;
  float compteurEnnemis { 0.0f };

  void updateTirs(float dt);
  void updateEnnemis(float dt);
};

#endif