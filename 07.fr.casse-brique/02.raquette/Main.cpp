#include "raylib.h"
#include <vector>
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;
const int BALLE_VITESSE = 5;
const int BALLE_TAILLE = 32;
const int RAQUETTE_LARGEUR = 128;
const int RAQUETTE_HAUTEUR = 32;
const int RAQUETTE_VITESSE = 10;
const int RAQUETTE_Y = 418;

Rectangle balle { 300, 200, BALLE_TAILLE, BALLE_TAILLE };
int vitesseBalleX = BALLE_VITESSE;
int vitesseBalleY = -BALLE_VITESSE;
Rectangle raquette { 300, RAQUETTE_Y, RAQUETTE_LARGEUR, RAQUETTE_HAUTEUR };

void load();
void update();
void draw();
void unload();

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
  InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Casse-brique");
  SetTargetFPS(60);
}

// Mise à jour de l'univers
void update() {
  // Mouvement balle
  balle.x = balle.x + vitesseBalleX;
  balle.y = balle.y + vitesseBalleY;
  // Rebond balle
  if(balle.x + BALLE_TAILLE > LARGEUR_ECRAN) {
    balle.x = LARGEUR_ECRAN - BALLE_TAILLE;
    vitesseBalleX = -vitesseBalleX;
  }
  if(balle.x < 0) {
    balle.x = 0;
    vitesseBalleX = -vitesseBalleX;
  }
  if(balle.y + BALLE_TAILLE > HAUTEUR_ECRAN) {
    balle.y = HAUTEUR_ECRAN - BALLE_TAILLE;
    vitesseBalleY = -vitesseBalleY;
  }
  if(balle.y < 0) {
    balle.y = 0;
    vitesseBalleY = -vitesseBalleY;
  }
  // Mouvement raquette
  if(IsKeyDown(KEY_A)) {
    raquette.x = raquette.x - RAQUETTE_VITESSE;
    if(raquette.x < 0) {
      raquette.x = 0;
    }
  }
  if(IsKeyDown(KEY_D)) {
    raquette.x = raquette.x + RAQUETTE_VITESSE;
    if(raquette.x + RAQUETTE_LARGEUR > LARGEUR_ECRAN) {
      raquette.x = LARGEUR_ECRAN - RAQUETTE_LARGEUR;
    }
  }
}

// Dessin de l'univers
void draw() {
  BeginDrawing();
  ClearBackground(BLACK);

  DrawRectangleRec(balle, WHITE);
  DrawRectangleRec(raquette, WHITE);

  EndDrawing();
}

// Déchargement du jeu
void unload() {
  CloseWindow();
}

