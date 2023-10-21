#include "Boss.h"
#include <math.h>

Boss::Boss(float xP, float yP) : Vaisseau{"images/boss.png", xP, yP, 0}
{
}

void Boss::update(float dt)
{
    Vaisseau::update(dt);
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

void Boss::updateChoixDeplacement()
{
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
        etat = EtatBoss::AttenteFin;
    }
}

void Boss::updateAttenteTir(float dt) {}

void Boss::updateTir(float dt) {}

void Boss::updateSuperTir(float dt) {}

void Boss::updateAttenteFin(float dt)
{
    if (chronoTir >= Constantes::BOSS_DUREE_TIR)
    {
        etat = EtatBoss::ChoixDeplacement;
    }
    chronoTir += dt;
}