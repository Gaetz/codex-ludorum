#ifndef PARALLAXE_H
#define PARALLAXE_H

#include "Sprite.h"
#include <string>
#include <vector>

using namespace std;

class Parallaxe {
public:
  Parallaxe(string chemin, int nbImagesP, float vitesseDefilementP, int largeurImageP);
  void load();
  void update(float dt);
  void draw();
  void unload();

private:
  vector<Sprite> images;
  int nbImages;
  float vitesseDefilement;
  int largeurImage;
};

#endif