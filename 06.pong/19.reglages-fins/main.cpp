#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;
const int VITESSE_RAQUETTE_GAUCHE = 4;
const int VITESSE_RAQUETTE_DROITE = 4;
const int VITESSE_BALLE = 5;
const int POINTS_POUR_MATCH = 7;
const int HAUTEUR_RAQUETTE = 128;
const int LARGEUR_RAQUETTE = 32;
const int TAILLE_BALLE = 64;

Rectangle balle { 50, 100, TAILLE_BALLE, TAILLE_BALLE };
int vitesseBalleX = VITESSE_BALLE;
int vitesseBalleY = -VITESSE_BALLE;

Rectangle raquetteGauche { 0, 100, LARGEUR_RAQUETTE, HAUTEUR_RAQUETTE };
Rectangle raquetteDroite { LARGEUR_ECRAN - 32, 100, LARGEUR_RAQUETTE, HAUTEUR_RAQUETTE };

int scoreGauche = 0;
int scoreDroite = 0;
int etatJeu = 0;
string texteResultat;
bool resultatVisible = false;

void load();
void update();
void draw();

void rebondSurRaquette(bool coteJoueur);
void relancerBalle(bool coteJoueur);

// Code
//----------------------------------------------------------------------------------
int main() {
    load();

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}

// Chargement du jeu
void load() {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Pong");
    SetTargetFPS(60);
}

// Mise à jour de l'univers
void update() {
    if (etatJeu == 0) {
        balle.x = balle.x + vitesseBalleX;
        balle.y = balle.y + vitesseBalleY;

        // Rebond sur le bord de l'écran
        if (balle.y < 0) {
            vitesseBalleY = -vitesseBalleY;
            balle.y = 0;
        }
        if (balle.y + balle.height > HAUTEUR_ECRAN) {
            vitesseBalleY = -vitesseBalleY;
            balle.y = HAUTEUR_ECRAN - balle.height;
        }
        if (balle.x < 0) {
            // L'IA gagne un point
            scoreDroite = scoreDroite + 1;
            // On replace la balle
            relancerBalle(true);
            // Victoire de l'IA
            if (scoreDroite >= POINTS_POUR_MATCH) {
                etatJeu = 2;
                texteResultat = "Défaite";
                resultatVisible = true;
            }
        }
        if (balle.x + balle.width > LARGEUR_ECRAN) {
            // Le joueur gagne un point
            scoreGauche = scoreGauche + 1;
            // On replace la balle
            relancerBalle(false);
            // Victoire du joueur humain
            if (scoreGauche >= POINTS_POUR_MATCH) {
                etatJeu = 1;
                texteResultat = "Victoire !";
                resultatVisible = true;
            }
        }

        // Mouvement raquette
        if (IsKeyDown(KEY_S)) {
            raquetteGauche.y = raquetteGauche.y + VITESSE_RAQUETTE_GAUCHE;
        } else if (IsKeyDown(KEY_W)) {
            raquetteGauche.y = raquetteGauche.y - VITESSE_RAQUETTE_GAUCHE;
        }

        // Blocage raquette
        if (raquetteGauche.y < 0) {
            raquetteGauche.y = 0;
        }
        int hauteurRaquette = raquetteGauche.height;
        if (raquetteGauche.y + hauteurRaquette > HAUTEUR_ECRAN) {
            raquetteGauche.y = HAUTEUR_ECRAN - hauteurRaquette;
        }
        if (raquetteDroite.y < 0) {
            raquetteDroite.y = 0;
        }
        if (raquetteDroite.y + hauteurRaquette > HAUTEUR_ECRAN) {
            raquetteDroite.y = HAUTEUR_ECRAN - hauteurRaquette;
        }

        // Collisions
        if (CheckCollisionRecs(raquetteGauche, balle)) {
            rebondSurRaquette(true);
        } else if (CheckCollisionRecs(raquetteDroite, balle)) {
            rebondSurRaquette(false);
        }

        // IA
        if (balle.y < raquetteDroite.y + hauteurRaquette / 4) {
            raquetteDroite.y = raquetteDroite.y - VITESSE_RAQUETTE_DROITE;
        } else if (balle.y > raquetteDroite.y + hauteurRaquette * 3 / 4) {
            raquetteDroite.y = raquetteDroite.y + VITESSE_RAQUETTE_DROITE;
        }
    } else {
        // Quand le jeu est fini
        if (IsKeyDown(KEY_R)) {
            scoreGauche = 0;
            scoreDroite = 0;
            texteResultat = "";
            resultatVisible = false;
            etatJeu = 0;
        }
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(to_string(scoreGauche).c_str(), 300, 50, 20, LIGHTGRAY);
    DrawText(to_string(scoreDroite).c_str(), 500, 50, 20, LIGHTGRAY);

    DrawRectangle(balle.x, balle.y, balle.width, balle.height, WHITE);
    DrawRectangleRec(raquetteGauche, WHITE);
    DrawRectangleRec(raquetteDroite, WHITE);

    if(resultatVisible) {
        DrawText(texteResultat.c_str(), 350, 200, 20, LIGHTGRAY);
    }

    EndDrawing();
}

void rebondSurRaquette(bool coteJoueur) {
    vitesseBalleX = -vitesseBalleX;
    if (coteJoueur) {
        balle.x = raquetteGauche.x + LARGEUR_RAQUETTE;
    } else {
        balle.x = raquetteDroite.x - TAILLE_BALLE;
    }
}

void relancerBalle(bool coteJoueur) {
    if (coteJoueur) {
        balle.x = TAILLE_BALLE * 2;
    } else {
        balle.x = LARGEUR_ECRAN - TAILLE_BALLE * 2;
    }
    balle.y = 100;
    vitesseBalleX = -vitesseBalleX;
}