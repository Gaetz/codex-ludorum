#ifndef GESTION_TEXTURES_H
#define GESTION_TEXTURES_H

#include "raylib.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct TextureStockee {
  string fichier;
  Texture2D texture;
};

class GestionTextures {
public:
  GestionTextures(vector<string> chargementTextures);
  void load();
  void unload();

  static Texture2D get(string fichier);

private:
  vector<string> fichiers;
  static vector<TextureStockee> stock;
};

#endif