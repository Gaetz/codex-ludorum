#include "Tile.h"
#include "Constantes.h"

Tile::Tile(string cheminTextureP, int xCarteP, int yCarteP, bool passableP) :
  Sprite {
    cheminTextureP,
    Constantes::coordX(xCarteP), Constantes::coordY(yCarteP),
    0, true
  },
  xCarte { xCarteP }, yCarte { yCarteP }, passable { passableP }
{

}