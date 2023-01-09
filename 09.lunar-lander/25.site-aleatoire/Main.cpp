#include "raylib.h"
#include "Lander.h"
#include "SiteAtterrissage.h"
#include "InterfaceLander.h"
#include "Constantes.h"

// Declarations
//----------------------------------------------------------------------------------

Lander lander {
    "assets/images/lander.png",
    (float)(Constantes::ECRAN_LARGEUR/2),
    0,
    true
};

SiteAtterrissage siteAtterrissage {
    "assets/images/cible.png", 400, 400
};

InterfaceLander interface { 50, 50, lander };

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
    InitWindow(Constantes::ECRAN_LARGEUR, Constantes::ECRAN_HAUTEUR, "Lander");
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
        interface.update(dt);

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
            interface.afficherTexteFin(etat);
            lander.eteindreFlamme();
        }
    }
    // Victoire ou défaite
    else {
        if (IsKeyPressed(KEY_R)) {
            etat = 0;
            // Replacer le lander
            lander.replacer();
            
            interface.cacherTexteFin();
            siteAtterrissage.changerSite();
        }
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    siteAtterrissage.draw();
    lander.draw();
    interface.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    lander.unload();
    siteAtterrissage.unload();
    CloseWindow();
}

