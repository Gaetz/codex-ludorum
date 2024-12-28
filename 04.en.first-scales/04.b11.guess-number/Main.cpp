#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(nullptr));
  int chosenNumber = rand() % 100 + 1;

  cout << "WHAT IS THE RIGHT NUMBER?" << endl;
  int proposal;
  bool victory = false;
  int nbTry = 0;

  while (!victory) {
    ++nbTry;
    cout << "Input a number between 1 and 100" << endl;
    cin >> proposal;

    if (proposal > chosenNumber && proposal <= 100) {
      cout << "Too big" << endl;
    } else if (proposal < chosenNumber && proposal >= 1) {
      cout << "Too small" << endl;
    } else if (proposal == chosenNumber) {
      cout << "Won!" << endl;
      victory = true;
      cout << "You have used " << nbTry << " attempts." << endl;
    } else {
      cout << "You did not enter a valid number." << endl;
    }
  }

  return 0;
}