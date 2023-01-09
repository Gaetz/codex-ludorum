#include "raylib.h"
#include "Constantes.h"
#include "Serpent.h"
#include <math.h>

using namespace std;


// Declarations
//----------------------------------------------------------------------------------

Serpent serpent {
    Constantes::SERPENT_X_DEPART,
    Constantes::SERPENT_Y_DEPART
};

Segment pomme {
    "images/pomme.png", 400, 96
};

void load();
void update();
void draw();
void unload();

void gestionPomme();

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
    InitWindow(Constantes::ECRAN_LARGEUR, Constantes::ECRAN_HAUTEUR, "Serpent");
    SetTargetFPS(60);

    serpent.load();
    pomme.load();
}

// Mise à jour de l'univers
void update() {
  float dt = GetFrameTime();
  serpent.update(dt);
  gestionPomme();
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    serpent.draw();
    pomme.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    serpent.unload();
    pomme.unload();
    CloseWindow();
}

void gestionPomme() {
// Pomme attrapée
  Rectangle rectangleTete = serpent.getRectangleTete();
  if (CheckCollisionRecs(rectangleTete, pomme.getRectangle())) {
    serpent.ajouterSegment();
    // Nouvelle position aleatoire de la pomme
    float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    float x = floor(nombreEntreZeroEtUn * (Constantes::ECRAN_LARGEUR));
    nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    float y = floor(nombreEntreZeroEtUn * (Constantes::ECRAN_HAUTEUR));
    x = x - ((int)x % (int)Constantes::SEGMENT_TAILLE);
    y = y - ((int)y % (int)Constantes::SEGMENT_TAILLE);
    pomme.positionner(x, y);
  }
}