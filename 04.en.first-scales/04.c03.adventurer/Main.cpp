#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Weapon {
  string name;
  int damage;
  float weight;
};

struct Adventurer {
  string name;
  int strength;
  int dext;
  int intel;
  int charisma;
  Weapon weapon;
};

void introduce(Adventurer adventurer) {
  cout << "*** " << adventurer.name << " ***" << endl;
  cout << "Strength: " << adventurer.strength << endl;
  cout << "Dexterity: " << adventurer.dext << endl;
  cout << "Intelligence: " << adventurer.intel << endl;
  cout << "Charisma: " << adventurer.charisma << endl;
  cout << adventurer.name << " is equipped with " << adventurer.weapon.name << endl;
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
  Weapon scimitar { "Giant scimitar", 12, 5 };
  Weapon dagger { "Dagger", 4, 0.25 };
  Adventurer hannor { "Hannor", 17, 12, 12, 8, scimitar };
  Adventurer ombreciel { "Ombreciel", 7, 12, 16, 15, dagger };
  introduce(hannor);
  introduce(ombreciel);
  cout << endl;

  vector<Adventurer> aventurers { hannor, ombreciel };
  float initiative = computeInitiative(aventurers);
  cout << "Initiative: " << initiative << endl;
}
