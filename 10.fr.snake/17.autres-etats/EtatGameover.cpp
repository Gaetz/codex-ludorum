#include "EtatGameover.h"
#include "Constantes.h"
#include "raylib.h"

void EtatGameover::load() {
  transition = ProchainEtat::None;
}

void EtatGameover::update(float dt) {
  if (IsKeyPressed(KEY_SPACE)) {
    transition = ProchainEtat::Menu;
  }
}

void EtatGameover::draw() {
  DrawText("Game Over",
    Constantes::ECRAN_LARGEUR / 2 - 50,
    Constantes::ECRAN_HAUTEUR / 2,
    20, WHITE);
}

void EtatGameover::unload() {

}

ProchainEtat EtatGameover::prochainEtat() {
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}