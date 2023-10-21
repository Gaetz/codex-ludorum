#ifndef SITE_ATTERRISSAGE_H
#define SITE_ATTERRISSAGE_H

#include "raylib.h"
#include <string>

using namespace std;

class SiteAtterrissage {
public:
    SiteAtterrissage(string cheminTextureP, float xP, float yP);
    void load();
    void draw();
    void unload();

    string cheminTexture { "" };
    Texture2D texture;
    float x { 0.0f };
    float y { 0.0f };
};

#endif