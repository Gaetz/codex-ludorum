#include "raylib.h"
#include "Lander.h"
#include "SiteAtterrissage.h"

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

SiteAtterrissage siteAtterrissage {
    "assets/images/cible.png", 400, 400 
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
    siteAtterrissage.load();
}

// Mise à jour de l'univers
void update() {
    float dt = GetFrameTime();
    lander.update(dt);
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    siteAtterrissage.draw();
    lander.draw();
    
    EndDrawing();
}

// Déchargement du jeu
void unload() {
    lander.unload();
    siteAtterrissage.unload();
    CloseWindow();
}
