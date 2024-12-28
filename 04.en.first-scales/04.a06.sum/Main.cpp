#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers {5, 14, 36, 87, 1};
  cout << numbers[0] << endl;
  int accumulator = 0;

  for (int number : numbers) {
    accumulator = accumulator + number;
  }
  cout << accumulator << endl;
  return  0;
}