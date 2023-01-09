#include "Constantes.h"

// Ecran
const int Constantes::ECRAN_LARGEUR { 800 };
const int Constantes::ECRAN_HAUTEUR { 600 };

// Serpent
const float Constantes::SEGMENT_TAILLE { 16.0f };
const float Constantes::HORLOGE { 0.15f };
const float Constantes::SERPENT_X_DEPART { 400.0f };
const float Constantes::SERPENT_Y_DEPART { 304.0f };

// Carte
const int Constantes::CARTE_TAILLE_X { 32 };
const int Constantes::CARTE_TAILLE_Y { 32 };

float Constantes::coordX(int xCarte) {
  return ECRAN_LARGEUR / 2
      - (ECRAN_LARGEUR / 2) % (int)SEGMENT_TAILLE
      - CARTE_TAILLE_X * SEGMENT_TAILLE / 2
      + xCarte * SEGMENT_TAILLE;
}

float Constantes::coordY(int yCarte) {
  return ECRAN_HAUTEUR / 2
      - (ECRAN_HAUTEUR / 2) % (int)SEGMENT_TAILLE
      - CARTE_TAILLE_Y * SEGMENT_TAILLE / 2
      + (yCarte+1) * SEGMENT_TAILLE; // Décalage
}