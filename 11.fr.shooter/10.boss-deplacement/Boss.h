#include "Vaisseau.h"

enum class EtatBoss {
	ChoixDeplacement,
	Deplacement,
	AttenteTir,
	Tir,
	SuperTir,
	AttenteFin
};

class Boss : public Vaisseau {
public:
    Boss(float xP, float yP);
    void update(float dt) override;
    void updateChoixDeplacement();
    void updateDeplacement(float dt);
    void updateAttenteTir(float dt);
    void updateTir(float dt);
    void updateSuperTir(float dt);
    void updateAttenteFin(float dt);

	EtatBoss etat { EtatBoss::ChoixDeplacement };
	float yCible { 0.0f };
	float chronoDeplacement { 0.0f };
	float chronoTir { 0.0f };
  float taille { 64.0f };
};