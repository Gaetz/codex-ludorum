#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"
#include "Vaisseau.h"

class EtatJeu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
  ProchainEtat prochainEtat() override;

private:
  Vaisseau vaisseau { 100.0f, 100.0f, 0 };
};

#endif