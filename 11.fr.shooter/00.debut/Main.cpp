#include "raylib.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 600;

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
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Shooter");
    SetTargetFPS(60);
}

// Mise à jour de l'univers
void update() {

}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);



    EndDrawing();
}

// Déchargement du jeu
void unload() {
    CloseWindow();
}

