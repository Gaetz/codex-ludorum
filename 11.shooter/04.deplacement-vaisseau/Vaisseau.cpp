#include "Vaisseau.h"

Vaisseau::Vaisseau(float xP, float yP, float rotationP) :
  Sprite{ "images/vaisseau.png", xP, yP, rotationP, true }
{

}

void Vaisseau::update(float dt) {
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

  x += vx * dt;
  y += vy * dt;
}