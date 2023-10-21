#include "SiteAtterrissage.h"
#include "Constantes.h"

using namespace std;

SiteAtterrissage::SiteAtterrissage(string cheminTextureP, float xP, float yP) :
    Sprite { cheminTextureP, xP, yP, 0.0f, false }
{
    
}

void SiteAtterrissage::changerSite() {
    float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    x = nombreEntreZeroEtUn * (Constantes::ECRAN_LARGEUR - Constantes::SITE_LARGEUR);
    nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    y = nombreEntreZeroEtUn * (Constantes::ECRAN_HAUTEUR - Constantes::SITE_MIN_Y) + Constantes::SITE_MIN_Y;
}