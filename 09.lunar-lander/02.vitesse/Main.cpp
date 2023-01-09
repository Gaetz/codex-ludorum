#include "raylib.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 600;
const float GRAVITE = 0.2f;

Texture2D lander;
float landerY;
float landerVy;

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
    landerVy = 0.0f;
    landerY = HAUTEUR_ECRAN/2 - lander.height/2;
}

// Mise à jour de l'univers
void update() {
    landerVy += GRAVITE;
    landerY += landerVy;
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexture(lander, LARGEUR_ECRAN/2 - lander.width/2, landerY, WHITE);

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    UnloadTexture(lander);
    CloseWindow();
}

