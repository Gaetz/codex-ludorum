#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers {5, 14, 36, 87, 1};
  cout << numbers[0] << endl;

  int accumulator = 0;
  accumulator = numbers[0] + numbers[1];
  cout << accumulator << endl;
  return  0;
}