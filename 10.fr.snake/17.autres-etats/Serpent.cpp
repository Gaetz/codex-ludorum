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
  // Réinitialise le serpent
  defaite = false;
  recommencer();
}

void Serpent::update(float dt) {
  // Gestion du temps
  horloge += dt;
  if (horloge >= Constantes::HORLOGE) {
    deplacer();
    horloge -= Constantes::HORLOGE;
    // Gestion de la defaite
    if (autocollision()) {
      recommencer();
      defaite = true;
    }
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
  for (int j = queue.size() - 1; j > 2; --j) {
    queue[j].unload();
    queue.erase(begin(queue) + j);
  }
}

bool Serpent::autocollision() {
  for (Segment& segment : queue) {
    if(tete.x == segment.x && tete.y == segment.y) {
      return true;
    }
  }
  return false;
}

Rectangle Serpent::getRectangleTete() {
  return tete.getRectangle();
}

void Serpent::ajouterSegment() {
  float coordX = queue[queue.size() - 1].x;
  float coordY = queue[queue.size() - 1].y + Constantes::SEGMENT_TAILLE;
  Segment nouveau { "images/segment.png", coordX, coordY };
  nouveau.load();
  queue.push_back(nouveau);
}

void Serpent::recommencer() {
  direction = 0;
  tete.positionner(Constantes::SERPENT_X_DEPART, Constantes::SERPENT_Y_DEPART);
  repositionnerQueue();
}

float Serpent::getX() {
  return tete.x;
}

float Serpent::getY() {
  return tete.y;
}

bool Serpent::getDefaite() {
  return defaite;
}