#ifndef PARTICULE_H
#define PARTICULE_H

#include "raylib.h"
#include <vector>

using namespace std;

class Particule {
public:
  Particule(float xP, float yP, Color couleurP);
  void update();
  void draw();

  float x { 0.0f };
  float y { 0.0f };
  float vx { (float)GetRandomValue(-20, 20)*.1f };
  float vy  { (float)GetRandomValue(-20, 20)*.1f };
  float taille { 5.0f };
  Color couleur { WHITE };
};

#endif