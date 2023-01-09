#include "EtatJeu.h"

void EtatJeu::load() {
  joueur.load();
  boss.load();
  compteurEnnemis = 0.0f;
  compteurGameOver = 0.0f;
  compteurVagues = 0;
  for (int i = 0; i < Constantes::NB_VAGUES; ++i) {
    Vague vague { i+1 };
    vagues.push_back(vague);
  }
}

void EtatJeu::update(float dt) {
  if (joueur.visible) {
    joueur.update(dt);
  }
  if (boss.etat != EtatBoss::Inactif) {
    boss.update(dt);
  }
  updateTirs(dt);
  updateEnnemis(dt);
  updateCollisions();
  updateGameover(dt);
}

void EtatJeu::draw() {
  joueur.draw();
  if (boss.etat != EtatBoss::Inactif) {
    boss.draw();
  }
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
  ProchainEtat nouvelEtat = transition;
  transition = ProchainEtat::None;
  return nouvelEtat;
}

void EtatJeu::updateTirs(float dt) {
  // Mettre à jour les tirs
  for(Tir& tir : tirs) {
    tir.update(dt);
  }
  // Tirer
  if(IsKeyPressed(KEY_SPACE) && joueur.visible) {
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
  if (compteurVagues < Constantes::NB_VAGUES
      && compteurEnnemis >= vagues[compteurVagues].chrono) {
    vagues[compteurVagues].parametrerVague(ennemis, boss);
    ++compteurVagues;
  }

  // Sortie de l'ecran
  for(int i = ennemis.size() - 1; i >= 0; --i) {
    if (ennemis[i].horsJeu()) {
      ennemis[i].unload();
      ennemis.erase(begin(ennemis) + i);
    }
  }
}

void EtatJeu::updateCollisions() {
  Rectangle rectJoueur = joueur.getRectangle();
  Rectangle rectBoss = boss.getRectangle();
  // Collisions boss / joueur
  if (CheckCollisionRecs(rectJoueur, rectBoss)) {
    joueur.vies = 0;
    joueur.visible = false;
  }

  // Collisions tirs
  for(int i = tirs.size() - 1; i >= 0; --i) {
    Rectangle rectTir = tirs[i].getRectangle();
    // Collisions tirs / joueur
    if (tirs[i].ennemi) {
      if (CheckCollisionRecs(rectJoueur, rectTir)) {
        if (joueur.degats(1)) {
          joueur.visible = false;
        }
        tirs[i].unload();
        tirs.erase(begin(tirs) + i);
      }
    } else {
      if (boss.etat != EtatBoss::Inactif) {
        // Collision tir / boss
        if (CheckCollisionRecs(rectBoss, rectTir)) {
          if (boss.degats(1)) {
            boss.visible = false;
            boss.etat = EtatBoss::Inactif;
          }
          tirs[i].unload();
          tirs.erase(begin(tirs) + i);
        }
      }
			// Collision tir / ennemi
      for(int j = ennemis.size() - 1; j >= 0; --j) {
        Rectangle rectEnnemi = ennemis[j].getRectangle();
        if(CheckCollisionRecs(rectEnnemi, rectTir)) {
          tirs[i].unload();
          tirs.erase(begin(tirs) + i);
          if (ennemis[j].degats(1)) {
            ennemis[j].unload();
            ennemis.erase(begin(ennemis) + j);
          }
        }
      }
    }
  }

  // Collisions ennemis / joueur
  for(int j = ennemis.size() - 1; j >= 0; --j) {
    Rectangle rectEnnemi = ennemis[j].getRectangle();
    if (CheckCollisionRecs(rectJoueur, rectEnnemi)) {
      joueur.vies = 0;
      joueur.visible = false;
      ennemis[j].vies = 0;
      ennemis[j].unload();
      ennemis.erase(begin(ennemis) + j);
    }
  }
}

void EtatJeu::updateGameover(float dt) {
  if (joueur.vies <= 0) {
    compteurGameOver += dt;
    if (compteurGameOver >= Constantes::DUREE_GAME_OVER) {
      for(int i = ennemis.size() - 1; i >= 0; --i) {
        ennemis[i].unload();
        ennemis.erase(begin(ennemis) + i);
      }
      transition = ProchainEtat::Gameover;
    }
  }
}