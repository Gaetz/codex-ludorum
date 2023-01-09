#include "EtatMenu.h"

void EtatMenu::load() {
  titre.load();
  for (Bouton& bouton : boutons) {
    bouton.load();
  }
  boutons[0].setSelection(true);
}

void EtatMenu::update(float dt) {
  // Mise à jour du bouton selectionné
  if (!boutons[indexBouton].getSelection()) {
    for (Bouton& bouton : boutons) {
      bouton.setSelection(false);
    }
    boutons[indexBouton].setSelection(true);
  }

  // Utilisation du clavier pour changer de bouton
  if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
    indexBouton = (indexBouton + 1) % maxIndexBouton;
  }
  else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
    indexBouton = (indexBouton - 1 + maxIndexBouton) % maxIndexBouton;
  }

  // Validation du bouton
  if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    switch (indexBouton) {
      case 0:
        transition = ProchainEtat::Jeu;
        break;
      case 1:
        CloseWindow();
        break;
    }
  }
}

void EtatMenu::draw() {
  titre.draw();
  for (Bouton& bouton : boutons) {
    bouton.draw();
  }
}

void EtatMenu::unload() {
  titre.unload();
  for (Bouton& bouton : boutons) {
    bouton.unload();
  }
}

ProchainEtat EtatMenu::prochainEtat() {
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}