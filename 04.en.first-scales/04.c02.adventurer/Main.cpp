#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Aventurier {
  std::string nom;
  int force;
  int dext;
  int intel;
  int charisme;
};

void presenter(Aventurier aventurier) {
  cout << "*** " << aventurier.nom << " ***" << endl;
  cout << "Force: " << aventurier.force << endl;
  cout << "Dextérité: " << aventurier.dext << endl;
  cout << "Intelligence: " << aventurier.intel << endl;
  cout << "Charisme: " << aventurier.charisme << endl;
}

int calculerInitiative(vector<Aventurier> aventuriers) {
  int accumulator = 0;
  for (Aventurier aventurier : aventuriers) {
    accumulator += aventurier.dext;
    accumulator += aventurier.intel;
  }
  int initiative = accumulator / aventuriers.size();
  return initiative;
}

int main() {
  Aventurier hannor { "Hannor", 17, 12, 12, 8 };
  Aventurier ombreciel { "Ombreciel", 7, 12, 16, 15 };
  presenter(hannor);
  presenter(ombreciel);
  cout << endl;

  vector<Aventurier> aventuriers { hannor, ombreciel };
  float initiative = calculerInitiative(aventuriers);
  cout << "Initiative: " << initiative << endl;
}