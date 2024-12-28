#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Adventurer {
  std::string name;
  int strength;
  int dext;
  int intel;
  int charisma;
};

void introduce(Adventurer adventurer) {
  cout << "*** " << adventurer.name << " ***" << endl;
  cout << "Strength: " << adventurer.strength << endl;
  cout << "Dexterity: " << adventurer.dext << endl;
  cout << "Intelligence: " << adventurer.intel << endl;
  cout << "Charisma: " << adventurer.charisma << endl;
}

int computeInitiative(vector<Adventurer> aventurers) {
  int accumulator = 0;
  for (Adventurer adventurer : aventurers) {
    accumulator += adventurer.dext;
    accumulator += adventurer.intel;
  }
  int initiative = accumulator / aventurers.size();
  return initiative;
}

int main() {
  Adventurer hannor { "Hannor", 17, 12, 12, 8 };
  Adventurer ombreciel { "Ombreciel", 7, 12, 16, 15 };
  introduce(hannor);
  introduce(ombreciel);
  cout << endl;

  vector<Adventurer> aventurers { hannor, ombreciel };
  float initiative = computeInitiative(aventurers);
  cout << "Initiative: " << initiative << endl;
}