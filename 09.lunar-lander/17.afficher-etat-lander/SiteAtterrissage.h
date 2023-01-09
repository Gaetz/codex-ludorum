#ifndef SITE_ATTERRISSAGE_H
#define SITE_ATTERRISSAGE_H

#include "raylib.h"
#include <string>

#include "Sprite.h"

using namespace std;

class SiteAtterrissage : public Sprite {
public:
    SiteAtterrissage(string cheminTextureP, float xP, float yP);
};

#endif