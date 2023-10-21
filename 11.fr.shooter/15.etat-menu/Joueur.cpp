#include <math.h>
#include "Joueur.h"

Joueur::Joueur(float xP, float yP) :
  Vaisseau { "images/vaisseau.png", xP, yP, 0 }
{
  vies = Constantes::VAISSEAU_VIES;
}

void Joueur::update(float dt) {
  // Contrôles
  if(IsKeyDown(KEY_D)) {
    vx += Constantes::VAISSEAU_ACCELERATION;
  }
  else if(IsKeyDown(KEY_A)) {
    vx -= Constantes::VAISSEAU_ACCELERATION;
  }
  if(IsKeyDown(KEY_S)) {
    vy += Constantes::VAISSEAU_ACCELERATION;
  }
  else if(IsKeyDown(KEY_W)) {
    vy -= Constantes::VAISSEAU_ACCELERATION;
  }
  vx *= Constantes::VAISSEAU_DECELERATON;
  vy *= Constantes::VAISSEAU_DECELERATON;

  // Rester à l'ecran
  Rectangle rect = getRectangle();
  if (rect.x < 0) {
    x = rect.width / 2;
  }
  else if (rect.x + rect.width > Constantes::ECRAN_LARGEUR) {
    x = Constantes::ECRAN_LARGEUR - rect.width / 2;
  }
  if (rect.y < 0) {
    y = rect.height / 2;
  }
  else if (rect.y + rect.height > Constantes::ECRAN_HAUTEUR) {
    y = Constantes::ECRAN_HAUTEUR - rect.height / 2;
  }

  Vaisseau::update(dt);
}
