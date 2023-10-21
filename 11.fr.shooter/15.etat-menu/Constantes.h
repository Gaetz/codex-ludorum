#ifndef CONSTANTES_H
#define CONSTANTES_H

class Constantes {
public:
  // Vaisseau
  static const float VAISSEAU_ACCELERATION;
  static const float VAISSEAU_DECELERATON;
  static const float VAISSEAU_DEPART_X;
  static const float VAISSEAU_DEPART_Y;
  static const int VAISSEAU_VIES;

  // Ecran
  static const float ECRAN_LARGEUR;
  static const float ECRAN_HAUTEUR;

  // Tir
  static const float TIR_VITESSE;

  // Ennemi
  static const float ENNEMI_PERIODE_APPARITION;
  static const float ENNEMI_VITESSE;
  static const float ENNEMI_ROTATION;
  static const float ENNEMI_COORD_SUPPRESSION;
  static const int ENNEMI_VIES;

  // Boss
  static const float BOSS_DUREE_DEPLACEMENT;
  static const float BOSS_VITESSE;
  static const float BOSS_DUREE_TIR;
  static const float BOSS_INTERVALLE_TIR;
  static const int BOSS_NB_TIR;
  static const int BOSS_NB_CHARGE_SUPER_TIR;
  static const int BOSS_NB_TIR_SUPER_TIR;
  static const int BOSS_VIES;
};

#endif