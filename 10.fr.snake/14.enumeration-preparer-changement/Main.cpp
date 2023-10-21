#include "raylib.h"
#include "Constantes.h"
#include "EtatJeu.h"
#include "EtatMenu.h"
#include "EtatGameover.h"
#include "GestionTextures.h"
#include "ProchainEtat.h"

using namespace std;


// Declarations
//----------------------------------------------------------------------------------

EtatMenu etatMenu {};
EtatJeu etatJeu {};
EtatGameover etatGameover {};
Etat& etatCourant = etatJeu;

vector<string> nomsTextures {
    "images/case.png",
    "images/mur.png",
    "images/pomme.png",
    "images/segment.png",
    "images/tete.png"
};

GestionTextures gestionTextures { nomsTextures };

void load();
void update();
void draw();
void unload();
void gererChangementEtat();
void changerEtat(Etat& nouvelEtat);

// Code
//----------------------------------------------------------------------------------
int main() {
    load();
    while (!WindowShouldClose()) {
        update();
        draw();
    }
    unload();
    return 0;
}


// Chargement du jeu
void load() {
    InitWindow(Constantes::ECRAN_LARGEUR, Constantes::ECRAN_HAUTEUR, "Serpent");
    SetTargetFPS(60);

    gestionTextures.load();
    etatCourant.load();
}

// Mise à jour de l'univers
void update() {
  float dt = GetFrameTime();
  etatCourant.update(dt);
  gererChangementEtat();
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    etatCourant.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    etatCourant.unload();
    gestionTextures.unload();

    CloseWindow();
}

// Choix du nouvel etat
void gererChangementEtat() {
  ProchainEtat prochainEtat = etatCourant.prochainEtat();
  switch (prochainEtat)
  {
  case ProchainEtat::Menu:
    changerEtat(etatMenu);
    break;

  case ProchainEtat::Jeu:
    changerEtat(etatJeu);
    break;

  case ProchainEtat::Gameover:
    changerEtat(etatGameover);
    break;

  default:
    break;
  }
}

// Changer l'etat
void changerEtat(Etat& nouvelEtat) {
  etatCourant.unload();
  etatCourant = nouvelEtat;
  etatCourant.load();
}