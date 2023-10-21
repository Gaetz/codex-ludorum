#ifndef BOUTON_H
#define BOUTON_H

#include "Sprite.h"
#include "Constantes.h"

using namespace std;

class Bouton : public Sprite {
public:
  Bouton(string cheminTextureSelP, string cheminTextureDeselP, float xP, float yP);
  void load() override;
  void unload() override;
  bool getSelection();
  void setSelection(bool selectionP);

private:
  Texture2D textureSelectionne;
  Texture2D textureDeselectionne;
  string cheminTextureSel;
  bool selection { false };
};

#endif