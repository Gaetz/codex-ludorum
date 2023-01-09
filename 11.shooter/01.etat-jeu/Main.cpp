#include "raylib.h"
#include "Etat.h"
#include "EtatMenu.h"
#include "EtatJeu.h"
#include "EtatGameOver.h"
#include "GestionTextures.h"

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 600;

void load();
void update();
void draw();
void unload();

EtatMenu etatMenu {};
EtatJeu etatJeu {};
EtatGameOver etatGameOver {};
Etat* etatCourant = &etatJeu;

vector<string> nomsTextures {

};

GestionTextures gestionTextures { nomsTextures };

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
    gestionTextures.load();
    etatCourant->load();
}

// Mise à jour de l'univers
void update() {
    float dt = GetFrameTime();
    etatCourant->update(dt);
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    etatCourant->draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    etatCourant->unload();
    gestionTextures.unload();
    CloseWindow();
}

