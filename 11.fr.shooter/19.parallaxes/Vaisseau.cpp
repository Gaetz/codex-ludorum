#include "Vaisseau.h"
#include <math.h>

Vaisseau::Vaisseau(string cheminTextureP, float rotationP,
           CoteEcran coteEcranEntreeP, CoteEcran coteEcranSortieP,
           float xCibleP, float yCibleP, float dureePhasePrincipaleP) :
  Sprite{ cheminTextureP, 0, 0, rotationP, true },
  coteEcranEntree {coteEcranEntreeP}, coteEcranSortie {coteEcranSortieP},
  xCible {xCibleP}, yCible {yCibleP}, dureePhasePrincipale {dureePhasePrincipaleP}
{
  changerPhase(Phase::Entree);
}

void Vaisseau::update(float dt) {
  switch (phase) {
    case Phase::Entree:
      updatePhaseEntree(dt);
      break;
    case Phase::Principale:
      updatePhasePrincipale(dt);
      break;
    case Phase::Sortie:
      updatePhaseSortie(dt);
      break;
  }
}

Tir Vaisseau::tirer(float rotation, bool ennemi) {
  Rectangle rect = getRectangle();
  float xTir = ennemi ? rect.x : rect.x + rect.width;
  Tir tir = Tir(xTir, y, rotation, ennemi);
  tir.load();
  tir.x = tir.x + tir.getRectangle().width / 2;
  return tir;
}

bool Vaisseau::degats(int nbDegats) {
	vies -= nbDegats;
	if (vies <= 0) {
		return true;
	}
	return false;
}

void Vaisseau::executerDeplacement(float dt) {
  x += vx * dt;
  y += vy * dt;
}

void Vaisseau::changerPhase(Phase nouvellePhase) {
  switch (nouvellePhase) {
    case Phase::Entree:
      phase = Phase::Entree;
      switch (coteEcranEntree) {
        case CoteEcran::Gauche:
          x = xCible - Constantes::ECRAN_LARGEUR;
          y = yCible;
          break;
        case CoteEcran::Droite:
          x = xCible + Constantes::ECRAN_LARGEUR;
          y = yCible;
          break;
        case CoteEcran::Haut:
          x = xCible;
          y = yCible - Constantes::ECRAN_HAUTEUR;
          break;
        case CoteEcran::Bas:
          x = xCible;
          y = yCible + Constantes::ECRAN_HAUTEUR;
          break;
      }
      break;
    case Phase::Principale:
      compteurPhasePrincipale = 0.0f;
      phase = Phase::Principale;
      break;
    case Phase::Sortie:
      phase = Phase::Sortie;
      switch (coteEcranSortie) {
        case CoteEcran::Gauche:
          xCible = x - Constantes::ECRAN_LARGEUR * 2;
          break;
        case CoteEcran::Droite:
          xCible = x + Constantes::ECRAN_LARGEUR * 2;
          break;
        case CoteEcran::Haut:
          yCible = y - Constantes::ECRAN_HAUTEUR * 2;
          break;
        case CoteEcran::Bas:
          yCible = y + Constantes::ECRAN_HAUTEUR * 2;
          break;
      }
      break;
  }
}

void Vaisseau::updatePhaseEntree(float dt) {
  deplacementVersCible(dt);
  executerDeplacement(dt);

  if(vx == 0 && vy == 0) {
    phase = Phase::Principale;
  }
}

void Vaisseau::deplacementVersCible(float dt) {
  float vitessePlacement = Constantes::VITESSE_PLACEMENT;

  if (x < xCible) {
    vx = vitessePlacement;
  } else if (x > xCible) {
    vx = -vitessePlacement;
  }
  if (abs(x - xCible) < vitessePlacement * dt) {
    vx = 0;
  }

  if (y < yCible) {
    vy = vitessePlacement;
  } else if (y > yCible) {
    vy = -vitessePlacement;
  }
  if (abs(y - yCible) < vitessePlacement * dt) {
    vy = 0;
  }
}

void Vaisseau::updatePhasePrincipale(float dt) {
  executerDeplacement(dt);
  if (dureePhasePrincipale != -1) {
    compteurPhasePrincipale += dt;
    if (compteurPhasePrincipale >= dureePhasePrincipale) {
      changerPhase(Phase::Sortie);
    }
  }
}

void Vaisseau::updatePhaseSortie(float dt) {
  deplacementVersCible(dt);
  executerDeplacement(dt);

  if (vx == 0 && vy == 0) {
    visible = false;
  }
}

bool Vaisseau::horsJeu() {
  return phase == Phase::Sortie && vx == 0 && vy == 0 &&
    ( x < 0 || x > Constantes::ECRAN_LARGEUR ||
      y < 0 || y > Constantes::ECRAN_HAUTEUR);
}


