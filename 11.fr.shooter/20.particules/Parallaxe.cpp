#include "Parallaxe.h"

Parallaxe::Parallaxe(string chemin, int nbImagesP,
                     float vitesseDefilementP, int largeurImageP) :
  nbImages { nbImagesP }, vitesseDefilement { vitesseDefilementP },
  largeurImage { largeurImageP }
{
  for (int i = 0; i < nbImages; ++i) {
    Sprite image { chemin, i * (float)largeurImage, 0, 0, false };
    images.push_back(image);
  }
}

void Parallaxe::load() {
  for (Sprite& image : images) {
    image.load();
  }
}

void Parallaxe::update(float dt)  {
  // Defilement
  for (Sprite& image : images) {
    image.x += vitesseDefilement * dt;
  }
  // Replacement des images
  int i { 0 };
  for (Sprite& image : images) {
    int imagePlusEloignee = (i + nbImages - 1) % nbImages;
		if (vitesseDefilement <= 0) {
			if (image.x <= -largeurImage) {
				image.x = (images[imagePlusEloignee].x + largeurImage);
			}
		} else {
			if (image.x >= largeurImage) {
				image.x = images[imagePlusEloignee].x - largeurImage;
			}
		}
    ++i;
  }
}

void Parallaxe::draw() {
  for (Sprite& image : images) {
    image.draw();
  }
}

void Parallaxe::unload()  {
  for (Sprite& image : images) {
    image.unload();
  }
}