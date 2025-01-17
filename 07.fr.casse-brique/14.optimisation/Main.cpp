#include "raylib.h"
#include <vector>
#include <string>

using namespace std;

// Types
//----------------------------------------------------------------------------------
struct Brique {
    Rectangle rect;
    bool visible;
};

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;
const int BALLE_VITESSE = 5;
const int BALLE_TAILLE = 32;
const int BALLE_DEPART_X = 300;
const int BALLE_DEPART_Y = 200;
const int RAQUETTE_LARGEUR = 128;
const int RAQUETTE_HAUTEUR = 32;
const int RAQUETTE_VITESSE = 10;
const int RAQUETTE_Y = 418;
const int BRIQUE_LARGEUR = 100;
const int BRIQUE_HAUTEUR = 32;
const int BRIQUES_LIGNES = 5;
const int BRIQUES_COLONNES = 8;
const int BRIQUES_SEPARATEUR = 2;
const int VIES_DEPART = 3;

Rectangle balle { BALLE_DEPART_X, BALLE_DEPART_Y, BALLE_TAILLE, BALLE_TAILLE };
int vitesseBalleX = BALLE_VITESSE;
int vitesseBalleY = -BALLE_VITESSE;
Rectangle raquette { 300, RAQUETTE_Y, RAQUETTE_LARGEUR, RAQUETTE_HAUTEUR };
vector<Brique> briques;
int nbVies = VIES_DEPART;
int nbBriques = BRIQUES_LIGNES * BRIQUES_COLONNES; 

Sound sonDefaite;
Sound sonRebondMur;
Sound sonOut;
Sound sonRebondBrique;
Sound sonRecommencer;
Sound sonVictoire;
bool sonVictoireJoue = false;
bool sonDefaiteJoue = false;


void load();
void update();
void draw();
void unload();
void recommencer();
int coordBriqueVersIndex(int ligneBrique, int colonneBrique);

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
  
  // Sons
  InitAudioDevice();
  sonDefaite = LoadSound("defaite.wav");
  sonRebondMur = LoadSound("rebondMur.wav");
  sonOut = LoadSound("out.wav");
  sonRebondBrique = LoadSound("rebondBrique.wav");
  sonRecommencer = LoadSound("recommencer.wav");
  sonVictoire = LoadSound("victoire.wav");
  
  // Briques
  for(int ligne = 0; ligne < BRIQUES_LIGNES; ++ligne) {
    for(int colonne = 0; colonne < BRIQUES_COLONNES; ++colonne) {
      Rectangle rect {};
      rect.x = BRIQUE_LARGEUR * colonne;
      rect.y = BRIQUE_HAUTEUR * ligne;
      rect.width = BRIQUE_LARGEUR;
      rect.height = BRIQUE_HAUTEUR;
      Brique brique { rect, true };
      briques.push_back(brique);
    }
  }
}

// Mise à jour de l'univers
void update() {
  if (nbVies <= 0) {
    if(!sonDefaiteJoue) {
        PlaySound(sonDefaite);
        sonDefaiteJoue = true;
    }
    if (IsKeyPressed(KEY_R)) {
      recommencer();
    }
  } else if (nbBriques <= 0) {
    if(!sonVictoireJoue) {
      PlaySound(sonVictoire);
      sonVictoireJoue = true;
    }
    if (IsKeyPressed(KEY_R)) {
      recommencer();
    }
  } else {
    // Mouvement balle
    balle.x = balle.x + vitesseBalleX;
    balle.y = balle.y + vitesseBalleY;
    // Rebond balle
    if(balle.x + BALLE_TAILLE > LARGEUR_ECRAN) {
      balle.x = LARGEUR_ECRAN - BALLE_TAILLE;
      vitesseBalleX = -vitesseBalleX;
      PlaySound(sonRebondMur);
    }
    if(balle.x < 0) {
      balle.x = 0;
      vitesseBalleX = -vitesseBalleX;
      PlaySound(sonRebondMur);
    }
    if(balle.y < 0) {
      balle.y = 0;
      vitesseBalleY = -vitesseBalleY;
      PlaySound(sonRebondMur);
    }
    // Mouvement raquette
    if(IsKeyDown(KEY_A)) {
      raquette.x = raquette.x - RAQUETTE_VITESSE;
      if(raquette.x < 0) {
        raquette.x = 0;
        PlaySound(sonRebondMur);
      }
    }
    if(IsKeyDown(KEY_D)) {
      raquette.x = raquette.x + RAQUETTE_VITESSE;
      if(raquette.x + RAQUETTE_LARGEUR > LARGEUR_ECRAN) {
        raquette.x = LARGEUR_ECRAN - RAQUETTE_LARGEUR;
        PlaySound(sonRebondMur);
      }
    }
    // Rebond balle-raquette
    if (CheckCollisionRecs(raquette, balle)) {
      balle.y = RAQUETTE_Y - BALLE_TAILLE;
      vitesseBalleY = -vitesseBalleY;
      PlaySound(sonRebondMur);
    }
    // Collisions balle-brique
    int colonneBrique = (balle.x + BALLE_TAILLE / 2) / BRIQUE_LARGEUR;
    int ligneBrique = balle.y / BRIQUE_HAUTEUR;
    int index = coordBriqueVersIndex(ligneBrique, colonneBrique);
    int maxBriques = BRIQUES_COLONNES * BRIQUES_LIGNES;
    if (index >= 0 && index < maxBriques && briques[index].visible) {
        vitesseBalleY = -vitesseBalleY;
        briques[index].visible = false;
        --nbBriques;
        if (nbBriques > 0) {
          PlaySound(sonRebondBrique);
        }
    }
    // Perte vie
    if(balle.y > HAUTEUR_ECRAN) {
      // Enlever une vie
      --nbVies;
      if(nbVies > 0) {
        PlaySound(sonOut);
      }
      // Replacer la balle
      balle.y = raquette.y - BALLE_TAILLE;
      balle.x = raquette.x + RAQUETTE_LARGEUR / 2 - BALLE_TAILLE / 2;
      vitesseBalleY = -vitesseBalleY;
    }
  }
}

// Dessin de l'univers
void draw() {
  BeginDrawing();
  ClearBackground(BLACK);

  string texteVies = "Vies : " + to_string(nbVies);
  DrawText(texteVies.c_str(), 700, 420, 20, LIGHTGRAY);
  DrawRectangleRec(balle, WHITE);
  DrawRectangleRec(raquette, WHITE);
  for (Brique brique : briques) {
    if(brique.visible) {
      DrawRectangle(brique.rect.x, brique.rect.y, 
                    brique.rect.width - BRIQUES_SEPARATEUR,
                    brique.rect.height - BRIQUES_SEPARATEUR,
                    WHITE);
    }
  }
  if (nbVies <= 0) {
    DrawText("Game Over", 
      LARGEUR_ECRAN / 2 - 40, 
      HAUTEUR_ECRAN / 2,
      20, LIGHTGRAY);
  }
  if (nbBriques <= 0) {
    DrawText("Victoire", 
      LARGEUR_ECRAN / 2 - 20, 
      HAUTEUR_ECRAN / 2,
      20, LIGHTGRAY);
  }
  EndDrawing();
}

// Déchargement du jeu
void unload() {
  CloseWindow();
}

void recommencer() {
  balle.x = BALLE_DEPART_X;
  balle.y = BALLE_DEPART_Y;
  vitesseBalleX = BALLE_VITESSE;
  vitesseBalleY = -BALLE_VITESSE;
  nbVies = VIES_DEPART;
  for(Brique& brique : briques) {
    brique.visible = true;
  }
  nbBriques = briques.size();
  sonVictoireJoue = false;
  sonDefaiteJoue = false;
  PlaySound(sonRecommencer);
}

int coordBriqueVersIndex(int ligneBrique, int colonneBrique) {
  return ligneBrique * BRIQUES_COLONNES + colonneBrique;
}