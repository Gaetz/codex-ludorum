#ifndef ETAT_GAMEOVER_H
#define ETAT_GAMEOVER_H

#include "Etat.h"
#include "Sprite.h"

class EtatGameOver : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;

private:
  ProchainEtat transition { ProchainEtat::None };
  Sprite titreGameover {
    "images/gameoverTitre.png",
    400, 300, 0, true
  };
};

#endif