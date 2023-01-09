#ifndef SERPENT_H
#define SERPENT_H

#include "Segment.h"
#include <vector>
#include "Constantes.h"

using namespace std;

class Serpent {
public:
  Serpent(float xP, float yP);
  void load();
  void update(float dt);
  void draw();
  void unload();

  Rectangle getRectangleTete();
  void ajouterSegment();
  void recommencer();
  float getX();
  float getY();
  bool getDefaite();

private:
  void deplacer();
  void repositionnerQueue();
  bool autocollision();

  int direction { 0 };
  float horloge { 0.0f };
  Segment tete { "images/tete.png", 400, 300 };
  vector<Segment> queue {
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE },
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE * 2 },
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE * 3 }
  };
  bool defaite { false };
};

#endif