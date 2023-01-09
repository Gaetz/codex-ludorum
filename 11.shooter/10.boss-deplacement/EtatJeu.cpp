#include "EtatJeu.h"

void EtatJeu::load() {
  joueur.load();
  boss.load();
  compteurEnnemis = 0.0f;
}

void EtatJeu::update(float dt) {
  joueur.update(dt);
  boss.update(dt);
  updateTirs(dt);
  updateEnnemis(dt);
}

void EtatJeu::draw() {
  joueur.draw();
  boss.draw();
  for(Tir& tir : tirs) {
    tir.draw();
  }
  for(Ennemi& ennemi : ennemis) {
    ennemi.draw();
  }
}

void EtatJeu::unload() {
  joueur.unload();
  boss.unload();
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
    tirs.push_back(joueur.tirer());
  }
  // Effacer les tirs hors de l'écran
  for(int i = tirs.size() - 1; i >= 0; --i) {
    if (tirs[i].x > Constantes::ECRAN_LARGEUR) {
      tirs[i].unload();
      tirs.erase(begin(tirs) + i);
    }
  }
}

void EtatJeu::updateEnnemis(float dt) {
  // Mise à jour
  for(Ennemi& ennemi : ennemis) {
    ennemi.update(dt);
  }

  // Apparition
  compteurEnnemis = compteurEnnemis + dt;
  if (compteurEnnemis >= Constantes::ENNEMI_PERIODE_APPARITION) {
    int limiteApparition = Constantes::ECRAN_HAUTEUR;
    float yEnnemi = (float)(rand() % limiteApparition);
    Ennemi ennemi = Ennemi(Constantes::ECRAN_LARGEUR, yEnnemi, PI);
    ennemi.load();
    ennemis.push_back(ennemi);
    compteurEnnemis = compteurEnnemis - Constantes::ENNEMI_PERIODE_APPARITION;
  }

  // Sortie de l'ecran
  for(int i = ennemis.size() - 1; i >= 0; --i) {
    if (ennemis[i].x < Constantes::ENNEMI_COORD_SUPPRESSION) {
      ennemis[i].unload();
      ennemis.erase(begin(ennemis) + i);
    }
  }
}