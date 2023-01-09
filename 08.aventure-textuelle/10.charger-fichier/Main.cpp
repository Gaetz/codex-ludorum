#include "raylib.h"
#include <string>

#include <fstream>
#include <sstream>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

string description = "";
string etat = "début";

void load();
void update();
void draw();
void unload();
string changerDescription();
void changerEtat(string nouvelEtat);

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
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Aventure");
    SetTargetFPS(60);
    changerEtat("debut");
}

// Mise à jour de l'univers
void update() {
    if (etat == "debut") {
        if (IsKeyPressed(KEY_S)) {
            changerEtat("sauter");
        }
        if (IsKeyPressed(KEY_C)) {
            changerEtat("cacher");
        }
    } else if (etat == "sauter") {
        if (IsKeyPressed(KEY_D)) {
            changerEtat("dague");
        }
        if (IsKeyPressed(KEY_A)) {
            changerEtat("cacher");
        }
    } else if (etat == "cacher") {
        if (IsKeyPressed(KEY_D)) {
            changerEtat("dague");
        }
        if (IsKeyPressed(KEY_F)) {
            changerEtat("fuite");
        }
        if (IsKeyPressed(KEY_P)) {
            changerEtat("pousser");
        }
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(description.c_str(), 50, 20, 20, WHITE); 

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    CloseWindow();
}

void changerEtat(string nouvelEtat) {
    etat = nouvelEtat;
    description = changerDescription();
}


string changerDescription() {
    string chemin = "textes/" + etat + ".txt";
    ifstream fichier { chemin };
    stringstream tampon;
    tampon << fichier.rdbuf();
    return tampon.str();
}