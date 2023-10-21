#ifndef ETAT_H
#define ETAT_H

#include "ProchainEtat.h"

class Etat {
public:
  virtual void load() = 0;
  virtual void update(float dt) = 0;
  virtual void draw() = 0;
  virtual void unload() = 0;

  virtual ProchainEtat prochainEtat() = 0;
};

#endif