#include "Constantes.h"
#include "raylib.h"

const float Constantes::VAISSEAU_ACCELERATION = { 250.0f };
const float Constantes::VAISSEAU_DECELERATON { 0.80f };
const float Constantes::VAISSEAU_DEPART_X { 50.0f };
const float Constantes::VAISSEAU_DEPART_Y { 300.0f };

const float Constantes::ECRAN_LARGEUR { 800.0f };
const float Constantes::ECRAN_HAUTEUR { 600.0f };

const float Constantes::TIR_VITESSE { 1000.0f };

const float Constantes::ENNEMI_PERIODE_APPARITION { 2.0f };
const float Constantes::ENNEMI_VITESSE { 200.0f };
const float Constantes::ENNEMI_ROTATION { PI };
const float Constantes::ENNEMI_COORD_SUPPRESSION { -200.0f };

  // Boss
const float Constantes::BOSS_DUREE_DEPLACEMENT = 1.5f;
const float Constantes::BOSS_VITESSE = 100.0f;
const float Constantes::BOSS_DUREE_TIR = 1.5f;
const float Constantes::BOSS_INTERVALLE_TIR = 0.3f;
const int Constantes::BOSS_NB_TIR = 3;
const int Constantes::BOSS_NB_CHARGE_SUPER_TIR = 2;
const int Constantes::BOSS_NB_TIR_SUPER_TIR = 12;