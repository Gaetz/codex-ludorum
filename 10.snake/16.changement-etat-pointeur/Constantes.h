#ifndef CONSTANTES_H
#define CONSTANTES_H

class Constantes {
public:
    // Ecran
    static const int ECRAN_LARGEUR;
    static const int ECRAN_HAUTEUR;

    // Serpent
    static const float SEGMENT_TAILLE;
    static const float HORLOGE;
    static const float SERPENT_X_DEPART;
    static const float SERPENT_Y_DEPART;

    // Carte
    static const int CARTE_TAILLE_X;
    static const int CARTE_TAILLE_Y;

    static float coordX(int xCarte);
    static float coordY(int yCarte);
    static int carteX(float x);
    static int carteY(float y);
};

#endif
