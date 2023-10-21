#ifndef ETAT_JEU_H
#define ETAT_JEU_H

#include "Etat.h"
#include "Constantes.h"
#include "Serpent.h"
#include "Tilemap.h"
#include <math.h>

class EtatJeu : public Etat {
public:
  void load() override;
  void update(float dt) override;
  void draw() override;
  void unload() override;

private:
  void gestionPomme();
  void gestionCollisionsCarte();

  Serpent serpent {
    Constantes::SERPENT_X_DEPART,
    Constantes::SERPENT_Y_DEPART
  };

  Segment pomme {
    "images/pomme.png",
    Constantes::coordX(16),
    Constantes::coordY(3),
  };

  Tilemap tilemap {};
};

#endif