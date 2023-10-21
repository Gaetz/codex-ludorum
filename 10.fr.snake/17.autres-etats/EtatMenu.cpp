#include "EtatMenu.h"
#include "Constantes.h"
#include "raylib.h"

void EtatMenu::load() {
  transition = ProchainEtat::None;
}

void EtatMenu::update(float dt) {
  if (IsKeyPressed(KEY_SPACE)) {
    transition = ProchainEtat::Jeu;
  }
}

void EtatMenu::draw() {
  DrawText("Snake",
    Constantes::ECRAN_LARGEUR / 2 - 30,
    Constantes::ECRAN_HAUTEUR / 2,
    20, WHITE);
}

void EtatMenu::unload() {

}

ProchainEtat EtatMenu::prochainEtat() {
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}