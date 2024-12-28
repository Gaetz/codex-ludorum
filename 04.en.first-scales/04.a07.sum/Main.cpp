#include <iostream>
#include <vector>

using namespace std;

int  sum(vector<int> numbers) {
  int accumulator = 0;
  for (int number : numbers) {
    accumulator = accumulator + number;
  }
  return accumulator;
}

int main() {
  vector<int> numbers {5, 14, 36, 87, 1};
  cout << numbers[0] << endl;

  int numbersSum =  sum(numbers);
  cout << numbersSum << endl;
  return  0;
}