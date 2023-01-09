#include "raylib.h"
#include "Constantes.h"
#include "Segment.h"

// Declarations
//----------------------------------------------------------------------------------

Segment tete { "images/tete.png", 400, 300 };

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
    InitWindow(Constantes::ECRAN_LARGEUR, Constantes::ECRAN_HAUTEUR, "Serpent");
    SetTargetFPS(60);

    tete.load();
}

// Mise à jour de l'univers
void update() {
    float dt = GetFrameTime();

}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    tete.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    tete.unload();
    CloseWindow();
}

