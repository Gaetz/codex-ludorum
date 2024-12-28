#include <iostream>

using namespace std;

int main() {
  int chosenNumber = 25;
  cout << chosenNumber << endl;
  cout << "WHAT IS THE RIGHT NUMBER?" << endl;
  int proposal;

  while(true) {
    cout << "Input a number between 1 and 100" << endl;
    cin >> proposal;
    cout << proposal << endl;

    if (proposal > chosenNumber && proposal <= 100) {
      cout << "Too big" << endl;
    } else if (proposal < chosenNumber && proposal >= 1) {
      cout << "Too small" << endl;
    } else if (proposal == chosenNumber) {
      cout << "Won!" << endl;
    } else {
      cout << "You did not enter a valid number." << endl;
    }
  }

  return 0;
}