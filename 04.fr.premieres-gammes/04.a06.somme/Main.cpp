#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nombres {5, 14, 36, 87, 1};
  cout << nombres[0] << endl;
  int accumulateur = 0;
  
  for (int nombre : nombres) {
    accumulateur = accumulateur + nombre;
  }
  cout << accumulateur << endl;
  return  0;
}