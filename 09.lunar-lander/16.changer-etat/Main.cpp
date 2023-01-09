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
    true
};

SiteAtterrissage siteAtterrissage {
    "assets/images/cible.png", 400, 400 
};

int etat = 0;

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
    // Jeu normal
    if (etat == 0) {
        lander.update(dt);
        Rectangle rectLander = lander.getRectangle();
        Rectangle rectSite = siteAtterrissage.getRectangle();
        if (CheckCollisionRecs(rectLander, rectSite)) {
            float xMaxLander = rectLander.x + rectLander.width;
            float xMaxSite = rectSite.x + rectSite.width;
            // Réussite
            if (rectLander.x >= rectSite.x && xMaxLander <= xMaxSite && lander.atterrissageOk()) {
                etat = 1;
            }
            // Crash
            else {
                etat = 2;
            }
        }
    } 
    // Victoire ou défaite
    else {
        if (IsKeyPressed(KEY_R)) {
            etat = 0;
            // Replacer le lander
        }
    }
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

