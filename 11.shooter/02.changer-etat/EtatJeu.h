#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"

class EtatJeu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;
};

#endif