#ifndef ETAT_MENU_H
#define ETAT_MENU_H

#include "Etat.h"

class EtatMenu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;
};

#endif