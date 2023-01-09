#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nombres {5, 14, 36, 87, 1};
  cout << nombres[0] << endl;

  int accumulateur = 0;
  accumulateur = nombres[0] + nombres[1]
    + nombres[2] + nombres[3] + nombres[4];
  cout << accumulateur << endl;
  return 0;
}