#include <iostream>

using namespace std;

int main() {
  int nombreChoisi = 25;
  cout << nombreChoisi << endl;
  cout << "QUEL EST LE BON NOMBRE ?" << endl;
  int proposition;
  bool victoire = false;
  int nbTentative = 0;
  
  while (!victoire) {
    ++nbTentative;
    cout << "Entrez un nombre entre 1 et 100" << endl;
    cin >> proposition;
    cout << proposition << endl;
    
    if (proposition > nombreChoisi && proposition <= 100) {
      cout << "Trop grand" << endl;
    } else if (proposition < nombreChoisi && proposition >= 1) {
      cout << "Trop petit" << endl;
    } else if (proposition == nombreChoisi) {
      cout << "Gagné !" << endl;
      victoire = true;
      cout << "Vous avez fait " << nbTentative << " tentatives." << endl;
    } else {
      cout << "Vous n'avez pas entré un nombre valide." << endl;
    }
  }
  
  return 0;
}