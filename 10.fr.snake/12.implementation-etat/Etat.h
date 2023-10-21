#ifndef ETAT_H
#define ETAT_H

class Etat {
public:
  virtual void load() = 0;
  virtual void update(float dt) = 0;
  virtual void draw() = 0;
  virtual void unload() = 0;
};

#endif