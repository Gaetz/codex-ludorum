#include "SiteAtterrissage.h"

SiteAtterrissage::SiteAtterrissage(string cheminTextureP, float xP, float yP) :
    cheminTexture { cheminTextureP },
    x { xP },
    y { yP }
{
    
}

void SiteAtterrissage::load() {
    texture = LoadTexture(cheminTexture.c_str());
}

void SiteAtterrissage::draw() {
    DrawTexture(texture, x, y, WHITE);
}

void SiteAtterrissage::unload() {
    UnloadTexture(texture);
}