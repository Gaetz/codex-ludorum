#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nombres {5, 14, 36, 87, 1};
  cout << nombres[0] << endl;
  int accumulateur = 0;
  
  int nbElements = nombres.size();
  for (int i = 0; i < nbElements; ++i) {
    accumulateur = accumulateur + nombres[i];
  }
  cout << accumulateur << endl;
  return  0;
}