#include "EtatJeu.h"

void EtatJeu::load() {
  vaisseau.load();
}

void EtatJeu::update(float dt) {
  vaisseau.update(dt);
  updateTirs(dt);
}

void EtatJeu::draw() {
  vaisseau.draw();
  for(Tir& tir : tirs) {
    tir.draw();
  }
}

void EtatJeu::unload() {
  vaisseau.unload();
  tirs.clear();
}

ProchainEtat EtatJeu::prochainEtat() {
  return ProchainEtat::None;
}

void EtatJeu::updateTirs(float dt) {
  // Mettre à jour les tirs
  for(Tir& tir : tirs) {
    tir.update(dt);
  }
  // Tirer
  if(IsKeyPressed(KEY_SPACE)) {
    tirs.push_back(vaisseau.tirer());
  }
  // Effacer les tirs hors de l'écran
  for(int i = tirs.size() - 1; i >= 0; --i) {
    if (tirs[i].x > Constantes::ECRAN_LARGEUR) {
      tirs[i].unload();
      tirs.erase(begin(tirs) + i);
    }
  }
}

