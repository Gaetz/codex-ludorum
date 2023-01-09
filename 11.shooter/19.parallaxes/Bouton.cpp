#include "Bouton.h"
#include "GestionTextures.h"

Bouton::Bouton(string cheminTextureSelP, string cheminTextureDeselP, float xP, float yP) :
  Sprite{ cheminTextureDeselP, xP, yP, 0, true },
  cheminTextureSel { cheminTextureSelP }
{

}

void Bouton::load() {
  Sprite::load();
  textureSelectionne = GestionTextures::get(cheminTextureSel);
  textureDeselectionne = texture;
}

void Bouton::unload() {
  Sprite::unload();
}

bool Bouton::getSelection() {
  return selection;
}


void Bouton::setSelection(bool selectionP) {
  selection = selectionP;
  if (selection) {
    texture = textureSelectionne;
  } else {
    texture = textureDeselectionne;
  }
}