#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Arme {
  string nom;
  int degats;
  float poids;
};

struct Aventurier {
  string nom;
  int force;
  int dext;
  int intel;
  int charisme;
  Arme arme;
};

void presenter(Aventurier aventurier) {
  cout << "*** " << aventurier.nom << " ***" << endl;
  cout << "Force: " << aventurier.force << endl;
  cout << "Dextérité: " << aventurier.dext << endl;
  cout << "Intelligence: " << aventurier.intel << endl;
  cout << "Charisme: " << aventurier.charisme << endl;
  cout << aventurier.nom << " est équipé d'un " << aventurier.arme.nom << endl;
}

int calculerInitiative(vector<Aventurier> aventuriers) {
  int accumulateur = 0;
  for (Aventurier aventurier : aventuriers) {
    accumulateur += aventurier.dext;
    accumulateur += aventurier.intel;
  }
  int initiative = accumulateur / aventuriers.size();
  return initiative;
}

int main() {
  Arme cimeterre { "Cimeterre géant", 12, 5 };
  Arme couteau { "Couteau de lancer", 4, 0.25 };
  Aventurier hannor { "Hannor", 17, 12, 12, 8, cimeterre };
  Aventurier ombreciel { "Ombreciel", 7, 12, 16, 15, couteau };
  presenter(hannor);
  presenter(ombreciel);
  cout << endl;

  vector<Aventurier> aventuriers { hannor, ombreciel };
  float initiative = calculerInitiative(aventuriers);
  cout << "Initiative: " << initiative << endl;
}
