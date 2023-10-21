#include "raylib.h"
#include "Constantes.h"
#include "Segment.h"
#include <vector>

using namespace std;


// Declarations
//----------------------------------------------------------------------------------

Segment tete { "images/tete.png", 400, 300 };
vector<Segment> queue {
    { "images/segment.png", 400, 300 + (float)Constantes::SEGMENT_TAILLE },
    { "images/segment.png", 400, 300 + (float)Constantes::SEGMENT_TAILLE * 2 },
    { "images/segment.png", 400, 300 + (float)Constantes::SEGMENT_TAILLE * 3 }
};


float horloge { 0.0f };

void deplacerSerpent();

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
    InitWindow(Constantes::ECRAN_LARGEUR, Constantes::ECRAN_HAUTEUR, "Serpent");
    SetTargetFPS(60);

    tete.load();
    for (Segment& segment : queue) {
        segment.load();
    }
}

// Mise à jour de l'univers
void update() {
    float dt = GetFrameTime();
    horloge += dt;
    if (horloge >= Constantes::HORLOGE) {
        deplacerSerpent();
        horloge -= Constantes::HORLOGE;
    }

}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    tete.draw();
    for (Segment& segment : queue) {
        segment.draw();
    }

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    for (Segment& segment : queue) {
        segment.unload();
    }
    CloseWindow();
}

void deplacerSerpent() {
    for (int i = queue.size() - 1; i > 0 ; --i) {
        queue[i].positionner(queue[i-1].x, queue[i-1].y);
    }
    queue[0].positionner(tete.x, tete.y);
    tete.x += Constantes::SEGMENT_TAILLE;
}
