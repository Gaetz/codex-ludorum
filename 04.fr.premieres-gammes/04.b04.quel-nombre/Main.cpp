#include <iostream>

using namespace std;

int main() {
  int nombreChoisi = 25;
  cout << nombreChoisi << endl;
  cout << "QUEL EST LE BON NOMBRE ?" << endl;
  cout << "Entrez un nombre entre 1 et 100" << endl;
  int proposition;
  cin >> proposition;
  cout << proposition << endl;
  
  if (proposition > nombreChoisi) {
    cout << "Trop grand" << endl;
  } else if (proposition < nombreChoisi) {
    cout << "Trop petit" << endl;
  } else if (proposition == nombreChoisi) {
    cout << "Gagné !" << endl;
  }
  
  return 0;
}