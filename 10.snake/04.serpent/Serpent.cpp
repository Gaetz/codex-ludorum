#include "Serpent.h"

Serpent::Serpent(float xP, float yP) {
  tete.positionner(xP, yP);
  repositionnerQueue();
}

void Serpent::load() {
  tete.load();
  for (Segment& segment : queue) {
      segment.load();
  }
}

void Serpent::update(float dt) {
  horloge += dt;
  if (horloge >= Constantes::HORLOGE) {
    deplacer();
    horloge -= Constantes::HORLOGE;
  }
}

void Serpent::draw() {
  tete.draw();
  for (Segment& segment : queue) {
    segment.draw();
  }
}

void Serpent::unload() {
  tete.unload();
  for (Segment& segment : queue) {
    segment.unload();
  }
}

void Serpent::deplacer() {
  for (int i = queue.size() - 1; i > 0 ; --i) {
      queue[i].positionner(queue[i-1].x, queue[i-1].y);
  }
  queue[0].positionner(tete.x, tete.y);
  tete.x += Constantes::SEGMENT_TAILLE;
}

void Serpent::repositionnerQueue() {
  for (unsigned int i = 1; i < queue.size() + 1; ++i) {
    queue[i-1].positionner(tete.x, tete.y + i * Constantes::SEGMENT_TAILLE);
  }
}
