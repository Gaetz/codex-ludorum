#include "raylib.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 600;

Texture2D lander;

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
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Lander");
    SetTargetFPS(60);
    
    lander = LoadTexture("assets/images/lander.png");
}

// Mise à jour de l'univers
void update() {

}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexture(lander, LARGEUR_ECRAN/2 - lander.width/2, HAUTEUR_ECRAN/2 - lander.height/2, WHITE);

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    UnloadTexture(lander);
    CloseWindow();
}

