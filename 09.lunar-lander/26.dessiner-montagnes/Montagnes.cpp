#include "Montagnes.h"
#include "Constantes.h"
#include <math.h>

Montagnes::Montagnes(float siteX, float siteY) {
    tracerLignes(siteX, siteY);
}

void Montagnes::tracerLignes(float siteX, float siteY) {
    int nombreSommets = Constantes::ECRAN_LARGEUR / Constantes::MONTAGNES_SEPARATION_SOMMETS;
    Vector2 debut { 0, (float)Constantes::MONTAGNES_HAUTEUR_DEPART };
    Vector2 fin { 0, (float)Constantes::MONTAGNES_HAUTEUR_DEPART };

    int iDebutSite = floor(((int)siteX - 1) / Constantes::MONTAGNES_SEPARATION_SOMMETS);
    bool doitDessinerFin = false;

    int i = 0;
    while (i < nombreSommets) {
        if (i == iDebutSite && !doitDessinerFin) {
            fin = { siteX, siteY };
            ajouterLigne(debut, fin);
            debut = { fin.x + Constantes::SITE_LARGEUR, fin.y };
            if (debut.x >= (i + 1) * Constantes::MONTAGNES_SEPARATION_SOMMETS) {
                i = floor(debut.x / Constantes::MONTAGNES_SEPARATION_SOMMETS);
            } else {
                doitDessinerFin = true;
            }
        } else if (i == iDebutSite && doitDessinerFin) {
            float hasard01 = (float)rand() / (float)RAND_MAX;
            fin = { (float)((i + 1) * Constantes::MONTAGNES_SEPARATION_SOMMETS),
                hasard01 * (Constantes::ECRAN_HAUTEUR - Constantes::MONTAGNES_HAUTEUR_MIN) + Constantes::MONTAGNES_HAUTEUR_MIN };
            ajouterLigne(debut, fin);
            debut = { fin.x, fin.y };
            ++i;
        } else {

            float hasard01 = (float)rand() / (float)RAND_MAX;
            fin = { (float)(debut.x + Constantes::MONTAGNES_SEPARATION_SOMMETS),
                hasard01 * (Constantes::ECRAN_HAUTEUR - Constantes::MONTAGNES_HAUTEUR_MIN) + Constantes::MONTAGNES_HAUTEUR_MIN };
            ajouterLigne(debut, fin);
            debut = { fin.x, fin.y };
            ++i;
        }
    }
}

void Montagnes::ajouterLigne(Vector2 debut, Vector2 fin) {
    Ligne ligne { debut, fin };
    lignes.push_back(ligne);
}

void Montagnes::effacerLignes() {
    lignes.clear();
}

void Montagnes::draw() {
    for(Ligne ligne : lignes) {
        DrawLineV(ligne.debut, ligne.fin, WHITE);
    }
}