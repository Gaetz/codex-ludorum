#include "EtatJeu.h"

void EtatJeu::load() {
  vaisseau.load();
}

void EtatJeu::update(float dt) {
  vaisseau.update(dt);
}

void EtatJeu::draw() {
  vaisseau.draw();
}

void EtatJeu::unload() {
  vaisseau.unload();
}

ProchainEtat EtatJeu::prochainEtat() {
  return ProchainEtat::None;
}