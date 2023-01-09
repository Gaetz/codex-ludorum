#include "SystemeParticules.h"

SystemeParticules::SystemeParticules(float x, float y, Color couleur) {
  particules.reserve(MAX_PARTICULES);
  for (int i = 0; i < MAX_PARTICULES; ++i) {
    particules.emplace_back(x, y, couleur);
  }
}

void SystemeParticules::update() {
  if (!actif) { return; }
  if (particules.size() <= 0) {
    actif = false;
  }

  for (Particule& particule : particules) {
    particule.update();
  }

  for (int i = particules.size() - 1; i >= 0; --i) {
    if (particules[i].taille <= 0) {
      particules.erase(begin(particules) + i);
    }
  }
}

void SystemeParticules::draw() {
  if (!actif) { return; }

  for (Particule& particule : particules) {
    particule.draw();
  }
}