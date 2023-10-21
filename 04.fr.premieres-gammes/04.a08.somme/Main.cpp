#include <iostream>
#include <vector>

using namespace std;

int somme(vector<int> nombres) {
  int accumulateur = 0;
  for (int nombre : nombres) {
    accumulateur = accumulateur + nombre;
  }
  return accumulateur;
}

int main() {
  vector<int> nombres {5, 14, 36, 87, 1};
  int sommeNombres = somme(nombres);
  cout << sommeNombres << endl;
  
   vector<int> autresNombres {4, 26, 12};
  int sommeAutresNombres = somme(autresNombres);
  cout << sommeAutresNombres << endl;
  return  0;
}