#include "Boss.h"
#include <math.h>

Boss::Boss(float xP, float yP, CoteEcran entree, CoteEcran sortie,
           vector<Tir>& tirsEtatJeuP) :
    Vaisseau{ "images/boss.png", 0, entree, sortie, xP, yP, -1 },
    tirsEtatJeu { tirsEtatJeuP }
{

}

void Boss::load() {
    Sprite::load();
    rotation = Constantes::ENNEMI_ROTATION;
    vies = Constantes::BOSS_VIES;
    etat = EtatBoss::ChoixDeplacement;
    chronoDeplacement = 0.0f;
    yCible = 0.0f;
	chronoTir = 0.0f;
	chargeSuperTir = 0.0f;
	nbTirs = 0;
}

void Boss::updatePhasePrincipale(float dt) {
    Vaisseau::updatePhasePrincipale(dt);
    switch (etat)
    {
    case EtatBoss::ChoixDeplacement:
        updateChoixDeplacement();
        break;
    case EtatBoss::Deplacement:
        updateDeplacement(dt);
        break;
    case EtatBoss::AttenteTir:
        updateAttenteTir(dt);
        break;
    case EtatBoss::Tir:
        updateTir(dt);
        break;
    case EtatBoss::SuperTir:
        updateSuperTir(dt);
        break;
    case EtatBoss::AttenteFin:
        updateAttenteFin(dt);
        break;
    default:
        updateChoixDeplacement();
        break;
    }
}

void Boss::updateChoixDeplacement() {
    const float demiHauteur = floor(texture.height / 2.0f);
    const float limiteDeplacement = Constantes::ECRAN_HAUTEUR - demiHauteur;
    yCible = (float)GetRandomValue(demiHauteur, limiteDeplacement);
    chronoDeplacement = 0.0;
    etat = EtatBoss::Deplacement;
}

void Boss::updateDeplacement(float dt)
{
    if (y < yCible) {
        vy = Constantes::BOSS_VITESSE;
    } else if (y > yCible) {
        vy = -Constantes::BOSS_VITESSE;
    }
    chronoDeplacement += dt;

    if (abs(y - yCible) < Constantes::BOSS_VITESSE * dt) {
        vy = 0.0f;
        chronoTir = 0.0f;
        etat = EtatBoss::AttenteTir;
    }
}

void Boss::updateAttenteTir(float dt) {
    if (chronoDeplacement < Constantes::BOSS_DUREE_TIR) {
        chronoDeplacement += dt;
    } else {
        if (chargeSuperTir < Constantes::BOSS_NB_CHARGE_SUPER_TIR) {
            etat = EtatBoss::Tir;
            chargeSuperTir++;
        } else {
            etat = EtatBoss::SuperTir;
            chargeSuperTir = 0;
        }
        nbTirs = 0;
    }
}

void Boss::updateTir(float dt) {
    if (nbTirs < Constantes::BOSS_NB_TIR) {
        if (chronoTir >= nbTirs * Constantes::BOSS_INTERVALLE_TIR) {
            Tir tir = tirer(Constantes::ENNEMI_ROTATION, true);
            tirsEtatJeu.push_back(tir);
            nbTirs++;
        }
    } else {
        etat = EtatBoss::AttenteFin;
    }
    chronoTir += dt;
}

void Boss::updateSuperTir(float dt) {
    if (nbTirs < Constantes::BOSS_NB_TIR) {
        if (chronoTir >= nbTirs * Constantes::BOSS_INTERVALLE_TIR) {
            const int nbSuperTirs = Constantes::BOSS_NB_TIR_SUPER_TIR;
            for (int i = 0; i < nbSuperTirs; ++i) {
                Tir tir = tirer(2.0f * PI / (float)nbSuperTirs * i, true);
                tirsEtatJeu.push_back(tir);
            }
            nbTirs++;
        }
    } else {
        etat = EtatBoss::AttenteFin;
    }
    chronoTir += dt;
}

void Boss::updateAttenteFin(float dt) {
    if (chronoTir >= Constantes::BOSS_DUREE_TIR)
    {
        etat = EtatBoss::ChoixDeplacement;
    }
    chronoTir += dt;
}
