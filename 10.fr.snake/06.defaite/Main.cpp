#include "raylib.h"
#include "Constantes.h"
#include "Serpent.h"

using namespace std;


// Declarations
//----------------------------------------------------------------------------------

Serpent serpent {
    Constantes::SERPENT_X_DEPART,
    Constantes::SERPENT_Y_DEPART
};

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

    serpent.load();
}

// Mise à jour de l'univers
void update() {
  float dt = GetFrameTime();
  serpent.update(dt);
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    serpent.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    serpent.unload();
    CloseWindow();
}
