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

private:
  void deplacer();
  void repositionnerQueue();

  int direction { 0 };
  float horloge { 0.0f };
  Segment tete { "images/tete.png", 400, 300 };
  vector<Segment> queue {
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE },
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE * 2 },
      { "images/segment.png", 400, 300 + Constantes::SEGMENT_TAILLE * 3 }
  };
};

#endif