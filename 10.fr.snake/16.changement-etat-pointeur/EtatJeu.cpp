#include "EtatJeu.h"

void EtatJeu::load() {
  tilemap.load();
  serpent.load();
  pomme.load();
}

void EtatJeu::update(float dt) {
  serpent.update(dt);
  gestionPomme();
  gestionCollisionsCarte();
}

void EtatJeu::draw() {
  tilemap.draw();
  serpent.draw();
  pomme.draw();
}

void EtatJeu::unload() {
  pomme.unload();
  serpent.unload();
  tilemap.unload();
}

void EtatJeu::gestionPomme() {
  // Pomme attrapée
  Rectangle rectangleTete = serpent.getRectangleTete();
  if (CheckCollisionRecs(rectangleTete, pomme.getRectangle())) {
    serpent.ajouterSegment();
    // Nouvelle position aleatoire de la pomme
    float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    int carteX = floor(nombreEntreZeroEtUn * (Constantes::CARTE_TAILLE_X - 2)) + 1;
    float x = Constantes::coordX(carteX);
    nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    int carteY = floor(nombreEntreZeroEtUn * (Constantes::CARTE_TAILLE_Y - 2)) + 1;
    float y = Constantes::coordY(carteY);
    pomme.positionner(x, y);
  }
}

void EtatJeu::gestionCollisionsCarte() {
  int carteX = Constantes::carteX(serpent.getX());
  int carteY = Constantes::carteY(serpent.getY());
  if (!tilemap.casePassable(carteX, carteY)) {
      transition = ProchainEtat::Gameover;
  }
}

ProchainEtat EtatJeu::prochainEtat() {
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}