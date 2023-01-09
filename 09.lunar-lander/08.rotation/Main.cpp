#include "raylib.h"
#include "Lander.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 600;

Lander lander { 
    "assets/images/lander.png", 
    LARGEUR_ECRAN/2,
    0,
    "assets/images/landerFlamme.png", 
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
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Lander");
    SetTargetFPS(60);
    
    lander.load();
}

// Mise à jour de l'univers
void update() {
    lander.update();
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    lander.draw();
    
    EndDrawing();
}

// Déchargement du jeu
void unload() {
    lander.unload();
    CloseWindow();
}

