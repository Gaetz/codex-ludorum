#include "Tilemap.h"
#include "Constantes.h"

Tilemap::Tilemap() {
  carte.reserve(tailleX * tailleY);
  for (int x = 0; x < tailleX; ++x) {
    for (int y = 0; y < tailleY; ++y) {
      if (x == 0 || y == 0 || x == tailleX-1 || y == tailleY-1) {
        Tile nouveau { "images/mur.png", x, y, false };
        carte.push_back(nouveau);
      } else {
        Tile nouveau { "images/case.png", x, y, true };
        carte.push_back(nouveau);
      }
    }
  }
}

void Tilemap::load() {
  for (int x = 0; x < tailleX; ++x) {
    for (int y = 0; y < tailleY; ++y) {
      carte[x * tailleY + y].load();
    }
  }
}

void Tilemap::draw() {
  for (int x = 0; x < tailleX; ++x) {
    for (int y = 0; y < tailleY; ++y) {
      carte[x * tailleY + y].draw();
    }
  }
}

void Tilemap::unload() {
  for (int x = 0; x < tailleX; ++x) {
    for (int y = 0; y < tailleY; ++y) {
      carte[x * tailleY + y].unload();
    }
  }
}

bool Tilemap::casePassable(int carteX, int carteY) {
  return carte[carteX * tailleY + carteY].passable;
}