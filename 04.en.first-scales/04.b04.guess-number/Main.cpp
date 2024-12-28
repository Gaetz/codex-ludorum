#include <iostream>

using namespace std;

int main() {
  int chosenNumber = 25;
  cout << chosenNumber << endl;
  cout << "WHAT IS THE RIGHT NUMBER?" << endl;
  cout << "Input a number between 1 and 100" << endl;
  int proposal;
  cin >> proposal;
  cout << proposal << endl;

  if (proposal > chosenNumber) {
    cout << "Too big" << endl;
  } else if (proposal < chosenNumber) {
    cout << "Too small" << endl;
  } else if (proposal == chosenNumber) {
    cout << "Won!" << endl;
  }

  return 0;
}