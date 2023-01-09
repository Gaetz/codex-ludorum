#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Constantes.h"
#include <string>
#include <vector>

using namespace std;

class Tilemap {
public:
  Tilemap();
  void load();
  void draw();
  void unload();
  bool casePassable(int carteX, int carteY);

  int tailleX { Constantes::CARTE_TAILLE_X };
  int tailleY { Constantes::CARTE_TAILLE_Y };
  int tailleCase { (int)Constantes::SEGMENT_TAILLE };
  vector<Tile> carte;
};

#endif