#include "raylib.h"
#include "Constantes.h"
#include "Serpent.h"
#include "GestionTextures.h"
#include "Tilemap.h"
#include <math.h>

using namespace std;


// Declarations
//----------------------------------------------------------------------------------

Serpent serpent {
    Constantes::SERPENT_X_DEPART,
    Constantes::SERPENT_Y_DEPART
};

Segment pomme {
    "images/pomme.png",
    Constantes::coordX(16),
    Constantes::coordY(3)
};

vector<string> nomsTextures {
    "images/case.png",
    "images/mur.png",
    "images/pomme.png",
    "images/segment.png",
    "images/tete.png"
};

GestionTextures gestionTextures { nomsTextures };

Tilemap tilemap {};

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

    gestionTextures.load();
    tilemap.load();
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

    tilemap.draw();
    serpent.draw();
    pomme.draw();

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    pomme.unload();
    serpent.unload();
    tilemap.unload();
    gestionTextures.unload();

    CloseWindow();
}

void gestionPomme() {
  // Pomme attrapée
  Rectangle rectangleTete = serpent.getRectangleTete();
  if (CheckCollisionRecs(rectangleTete, pomme.getRectangle())) {
    serpent.ajouterSegment();
    // Nouvelle position aleatoire de la pomme
    float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    int carteX = floor(nombreEntreZeroEtUn * (Constantes::CARTE_TAILLE_X - 2)) + 1;
    float x = Constantes::coordX(carteX);
    nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    int carteY = floor(nombreEntreZeroEtUn * (Constantes::CARTE_TAILLE_Y - 2)) + 1;
    float y = Constantes::coordY(carteY);
    pomme.positionner(x, y);
  }
}