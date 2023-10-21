#ifndef ETAT_MENU_H
#define ETAT_MENU_H

#include "Etat.h"
#include <vector>
#include "Bouton.h"

using namespace std;

class EtatMenu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;

  Sprite titre {"images/menuTitre.png", 400, 200, 0, true };

  vector<Bouton> boutons {
    Bouton { "images/menuJouerSelection.png", "images/menuJouer.png", 400, 400 },
    Bouton { "images/menuQuitterSelection.png", "images/menuQuitter.png", 400, 500 },
  };

  int indexBouton { 0 };
  const int maxIndexBouton { 2 };
  ProchainEtat transition { ProchainEtat::None };
};

#endif