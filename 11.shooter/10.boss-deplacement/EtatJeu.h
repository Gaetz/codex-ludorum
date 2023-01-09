#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"
#include <vector>
#include "Ennemi.h"
#include "Joueur.h"
#include "Boss.h"

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

  Boss boss {
    Constantes::ECRAN_LARGEUR - 200,
    Constantes::ECRAN_HAUTEUR / 2
  };

  void updateTirs(float dt);
  void updateEnnemis(float dt);
};

#endif