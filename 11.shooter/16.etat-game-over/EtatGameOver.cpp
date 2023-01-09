#include "EtatGameOver.h"

void EtatGameOver::load() {
  titreGameover.load();
}

void EtatGameOver::update(float dt) {
  if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
    transition = ProchainEtat::Menu;
  }
}

void EtatGameOver::draw() {
  titreGameover.draw();
}

void EtatGameOver::unload() {
  titreGameover.unload();
}

ProchainEtat EtatGameOver::prochainEtat() {
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}