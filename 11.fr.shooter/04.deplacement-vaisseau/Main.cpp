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
void gererChangementEtat();
void changerEtat(Etat* nouvelEtat);

EtatMenu etatMenu {};
EtatJeu etatJeu {};
EtatGameOver etatGameOver {};
Etat* etatCourant = &etatJeu;

vector<string> nomsTextures {
    "images/vaisseau.png"
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
    gererChangementEtat();
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

// Choix du nouvel etat
void gererChangementEtat() {
    ProchainEtat prochainEtat = etatCourant->prochainEtat();
    switch (prochainEtat)
    {
    case ProchainEtat::Menu:
        changerEtat(&etatMenu);
        break;
    case ProchainEtat::Jeu:
        changerEtat(&etatJeu);
        break;
    case ProchainEtat::Gameover:
        changerEtat(&etatGameOver);
        break;
    default:
        break;
    }
}

// Changer l'etat
void changerEtat(Etat* nouvelEtat) {
    etatCourant->unload();
    etatCourant = nouvelEtat;
    etatCourant->load();
}

