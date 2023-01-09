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
  // Gestion du temps
  horloge += dt;
  if (horloge >= Constantes::HORLOGE) {
    deplacer();
    horloge -= Constantes::HORLOGE;
  }
  // Direction
  if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
    if (direction == 0 || direction == 8 ) { return; }
    direction = 2;
  } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
    if (direction == 2 ) { return; }
    direction = 8;
  } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
    if (direction == 6 ) { return; }
    direction = 4;
  } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
    if (direction == 4 ) { return; }
    direction = 6;
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
  if (direction != 0) {
    for (int i = queue.size() - 1; i > 0 ; --i) {
        queue[i].positionner(queue[i-1].x, queue[i-1].y);
    }
    queue[0].positionner(tete.x, tete.y);
  }
  switch (direction) {
    case 2:
      tete.y += Constantes::SEGMENT_TAILLE;
      break;
    case 4:
      tete.x -= Constantes::SEGMENT_TAILLE;
      break;
    case 6:
      tete.x += Constantes::SEGMENT_TAILLE;
      break;
    case 8:
      tete.y -= Constantes::SEGMENT_TAILLE;
      break;
    default:
      break;
  }
}

void Serpent::repositionnerQueue() {
  for (unsigned int i = 1; i < queue.size() + 1; ++i) {
    queue[i-1].positionner(tete.x, tete.y + i * Constantes::SEGMENT_TAILLE);
  }
}
