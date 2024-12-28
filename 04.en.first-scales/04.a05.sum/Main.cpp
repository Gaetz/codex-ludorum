#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers {5, 14, 36, 87, 1};
  cout << numbers[0] << endl;
  int accumulator = 0;

  int nbElements = numbers.size();
  for (int i = 0; i < nbElements; ++i) {
    accumulator = accumulator + numbers[i];
  }
  cout << accumulator << endl;
  return  0;
}