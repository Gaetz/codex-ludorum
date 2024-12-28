#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> numbers) {
  int accumulator = 0;
  for (int number : numbers) {
    accumulator = accumulator + number;
  }
  return accumulator;
}

int main() {
  vector<int> numbers {5, 14, 36, 87, 1};
  int numbersSum = sum(numbers);
  cout << numbersSum << endl;

   vector<int> otherNumbers {4, 26, 12};
  int otherNumbersSum = sum(otherNumbers);
  cout << otherNumbersSum << endl;
  return  0;
}