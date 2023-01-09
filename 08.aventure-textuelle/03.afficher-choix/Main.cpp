#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

string description = 
"Le magicien sort de l'ombre. Il jette sur vous un regard\n"
"méprisant et ses doigts se crispent sur la sphère\n"
"crépitante qu'il tient à la main.\n"
"- Vous introduire dans ma tour aura été votre dernière\n"
"erreur, apprenti.\n"
"Sa voix semble étrangement lointaine et ses yeux sont\n" 
"révulsés dans ses orbites. Vous comprenez avec horreur\n"
"qu'il invoquait un sortilège mortel tandis qu'il vous\n" 
"parlait. Vous n'avez qu'un instant pour réagir !\n\n"
"S - Sauter sur le côté\n"
"C - Vous cacher derrière un meuble\n"
;

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
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Aventure");
    SetTargetFPS(60);
}

// Mise à jour de l'univers
void update() {

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

