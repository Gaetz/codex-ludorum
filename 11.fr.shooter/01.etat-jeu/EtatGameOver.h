#ifndef ETAT_GAMEOVER_H
#define ETAT_GAMEOVER_H

#include "Etat.h"

class EtatGameOver : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
};

#endif