#include "raylib.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

Rectangle balle { 50, 100, 32, 32 };
int vitesseBalleX = 5;
int vitesseBalleY = -5;

Rectangle raquetteGauche { 0, 100, 32, 128 };
int vitesseRaquetteGauche = 4;

void load();
void update();
void draw();

void rebondSurRaquette();

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
        vitesseBalleX = -vitesseBalleX;
        balle.x = 0;
    }
    if (balle.x + balle.height > LARGEUR_ECRAN) {
        vitesseBalleX = -vitesseBalleX;
        balle.x = LARGEUR_ECRAN - balle.height;
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

    // Collisions
    if (CheckCollisionRecs(raquetteGauche, balle)) {
        rebondSurRaquette();
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangle(balle.x, balle.y, balle.width, balle.height, WHITE);
    DrawRectangleRec(raquetteGauche, WHITE);

    EndDrawing();
}

void rebondSurRaquette() {
    vitesseBalleX = -vitesseBalleX;
}

/*
bool collision(Rectangle a, Rectangle b) {
    int xMinA = a.x;
    int yMinA = a.y;
    int xMaxA = a.x + a.width;
    int yMaxA = a.y + a.height;
    int xMinB = b.x;
    int yMinB = b.y;
    int xMaxB = b.x + b.width;
    int yMaxB = b.y + b.height;
    return ( !(xMinB > xMaxA || yMinB > yMaxA
            || xMaxB < xMinA || yMaxB < yMinA));
}
*/
