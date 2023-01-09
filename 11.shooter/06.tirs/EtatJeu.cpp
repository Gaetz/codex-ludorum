#include "EtatJeu.h"

void EtatJeu::load() {
  vaisseau.load();
}

void EtatJeu::update(float dt) {
  vaisseau.update(dt);
  for(Tir& tir : tirs) {
    tir.update(dt);
  }

  if(IsKeyPressed(KEY_SPACE)) {
    tirs.push_back(vaisseau.tirer());
  }
}

void EtatJeu::draw() {
  vaisseau.draw();
  for(Tir& tir : tirs) {
    tir.draw();
  }
}

void EtatJeu::unload() {
  vaisseau.unload();
}

ProchainEtat EtatJeu::prochainEtat() {
  return ProchainEtat::None;
}