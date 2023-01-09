#include "GestionTextures.h"

vector<TextureStockee> GestionTextures::stock {};

GestionTextures::GestionTextures(vector<string> chargementTextures) :
  fichiers { chargementTextures }
{

}

void GestionTextures::load() {
  // Texture par défaut stockée en premier
  Texture2D textureDefault = LoadTexture("images/defaut.png");
  TextureStockee stockeeDefaut { "defaut", textureDefault };
  stock.push_back(stockeeDefaut);
  // Autres textures
  for (string fichier : fichiers) {
    Texture2D texture = LoadTexture(fichier.c_str());
    TextureStockee stockee { fichier, texture };
    stock.push_back(stockee);

    TraceLog(LOG_INFO, "La texture [%s] a été chargée.", fichier.c_str());
  }
}

Texture2D GestionTextures::get(string nom) {
  for(TextureStockee& textureStockee : stock) {
    if (textureStockee.fichier == nom) {
      return textureStockee.texture;
    }
  }
  // Pas de texture avec ce nom, renvoie la texture par défaut
  TraceLog(LOG_WARNING, "La texture [%s] n'existe pas dans le gestionnaire de textures.", nom.c_str());
  return stock[0].texture;
}

void GestionTextures::unload() {
  for(TextureStockee textureStockee : stock) {
    UnloadTexture(textureStockee.texture);
  }
}
