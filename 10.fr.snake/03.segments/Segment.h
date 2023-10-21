#ifndef SEGMENT_H
#define SEGMENT_H

#include "Sprite.h"
#include <string>

using namespace std;

class Segment : public Sprite {
public:
    Segment(string cheminTextureP, float xP, float yP);
    void positionner(float xP, float yP);
};

#endif