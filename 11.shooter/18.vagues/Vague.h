#ifndef VAGUE_H
#define VAGUE_H

#include "Ennemi.h"
#include "Boss.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Vague {
public:
  Vague(int id);
  void parametrerVague(vector<Ennemi>& ennemis, Boss& boss);
  float chrono { 0.0f };

private:
  CoteEcran coteEcran(string s);
  vector<string> lignesFichier;
};

#endif