#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

Rectangle balle { 50, 100, 32, 32 };
int vitesseBalleX = 5;
int vitesseBalleY = -5;

Rectangle raquetteGauche { 0, 100, 32, 128 };
int vitesseRaquetteGauche = 4;

Rectangle raquetteDroite { LARGEUR_ECRAN - 32, 100, 32, 128 };
int vitesseRaquetteDroite = 4;

int scoreGauche = 0;
int scoreDroite = 0;

void load();
void update();
void draw();

void rebondSurRaquette(bool coteJoueur);
void relancerBalle(bool coteJoueur);

// Code
//----------------------------------------------------------------------------------
int main() {
    load();

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}

// Chargement du jeu
void load() {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Pong");
    SetTargetFPS(60);
}

// Mise à jour de l'univers
void update() {
    balle.x = balle.x + vitesseBalleX;
    balle.y = balle.y + vitesseBalleY;

    // Rebond sur le bord de l'écran
    if (balle.y < 0) {
        vitesseBalleY = -vitesseBalleY;
        balle.y = 0;
    }
    if (balle.y + balle.height > HAUTEUR_ECRAN) {
        vitesseBalleY = -vitesseBalleY;
        balle.y = HAUTEUR_ECRAN - balle.height;
    }
    if (balle.x < 0) {
        // L'IA gagne un point
        // On replace la balle
        relancerBalle(true);
    }
    if (balle.x + balle.width > LARGEUR_ECRAN) {
        // Le joueur gagne un point
        // On replace la balle
        relancerBalle(false);
    }

    // Mouvement raquette
    if (IsKeyDown(KEY_S)) {
        raquetteGauche.y = raquetteGauche.y + vitesseRaquetteGauche;
    } else if (IsKeyDown(KEY_W)) {
        raquetteGauche.y = raquetteGauche.y - vitesseRaquetteGauche;
    }

    // Blocage raquette
    if (raquetteGauche.y < 0) {
        raquetteGauche.y = 0;
    }
    int hauteurRaquette = raquetteGauche.height;
    if (raquetteGauche.y + hauteurRaquette > HAUTEUR_ECRAN) {
        raquetteGauche.y = HAUTEUR_ECRAN - hauteurRaquette;
    }
    if (raquetteDroite.y < 0) {
        raquetteDroite.y = 0;
    }
    if (raquetteDroite.y + hauteurRaquette > HAUTEUR_ECRAN) {
        raquetteDroite.y = HAUTEUR_ECRAN - hauteurRaquette;
    }

    // Collisions
    if (CheckCollisionRecs(raquetteGauche, balle)) {
        rebondSurRaquette(true);
    } else if (CheckCollisionRecs(raquetteDroite, balle)) {
        rebondSurRaquette(false);
    }

    // IA
    if (balle.y < raquetteDroite.y + hauteurRaquette / 4) {
        raquetteDroite.y = raquetteDroite.y - vitesseRaquetteDroite;
    } else if (balle.y > raquetteDroite.y + hauteurRaquette * 3 / 4) {
        raquetteDroite.y = raquetteDroite.y + vitesseRaquetteDroite;
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(to_string(scoreGauche).c_str(), 300, 50, 20, LIGHTGRAY);
    DrawText(to_string(scoreDroite).c_str(), 500, 50, 20, LIGHTGRAY);

    DrawRectangle(balle.x, balle.y, balle.width, balle.height, WHITE);
    DrawRectangleRec(raquetteGauche, WHITE);
    DrawRectangleRec(raquetteDroite, WHITE);

    EndDrawing();
}

void rebondSurRaquette(bool coteJoueur) {
    vitesseBalleX = -vitesseBalleX;
    if (coteJoueur) {
        balle.x = raquetteGauche.x + 32;
    } else {
        balle.x = raquetteDroite.x - 32;
    }
}

void relancerBalle(bool coteJoueur) {
    if (coteJoueur) {
        balle.x = 50;
    } else {
        balle.x = LARGEUR_ECRAN - 50;
    }
    balle.y = 100;
    vitesseBalleX = -vitesseBalleX;
}