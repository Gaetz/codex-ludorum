#ifndef BOSS_H
#define BOSS_H

#include "Vaisseau.h"
#include <vector>

using std::vector;

enum class EtatBoss {
	Inactif,
	ChoixDeplacement,
	Deplacement,
	AttenteTir,
	Tir,
	SuperTir,
	AttenteFin
};

class Boss : public Vaisseau {
public:
	Boss(float xP, float yP, CoteEcran entree, CoteEcran sortie,
			vector<Tir>& tirsEtatJeuP);
	void load() override;
	void updatePhasePrincipale(float dt) override;
	void updateChoixDeplacement();
	void updateDeplacement(float dt);
	void updateAttenteTir(float dt);
	void updateTir(float dt);
	void updateSuperTir(float dt);
	void updateAttenteFin(float dt);
	void parametrer(float xCibleP, float yCibleP, CoteEcran entree, CoteEcran sortie);

	EtatBoss etat { EtatBoss::Inactif };
	float yCible { 0.0f };
	float chronoDeplacement { 0.0f };
	float chronoTir { 0.0f };
  float taille { 64.0f };
	float chargeSuperTir { 0.0f };
	int nbTirs { 0 };
	vector<Tir>& tirsEtatJeu;
};

#endif