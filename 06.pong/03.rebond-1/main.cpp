#include "raylib.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

int xBalle = 50;
int yBalle = 100;
int tailleBalle = 32;
int vitesseBalleX = 5;
int vitesseBalleY = -5;


void load();
void update();
void draw();

// Code
//----------------------------------------------------------------------------------
int main() {
    load();

    while (!WindowShouldClose()) {
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
    xBalle = xBalle + vitesseBalleX;
    yBalle = yBalle + vitesseBalleY;

    // Rebond sur le bord de l'écran
    if (yBalle < 0) {
        vitesseBalleY = -vitesseBalleY;
        yBalle = 0;
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangle(xBalle, yBalle, tailleBalle, tailleBalle, WHITE);

    EndDrawing();
}