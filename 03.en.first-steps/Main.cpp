#include <iostream>
#include <string>
#include <vector>

using namespace std;

void manners() {
  cout << "Hi." << endl;
  cout << "How are you?" << endl;
  cout << "What a beautiful day today!" << endl;
}

void greatEach(vector<string> names) {
  for (string name : names) {
    cout << "Hello " << name << endl;
  }
}

void addName(vector<string>& names, int& nbPeople, string name) {
  names.push_back(name);
  nbPeople = names.size();
}

void greatEachInverse(vector<string> names) {
  int length = names.size();
  for (int i = 0; i < length; ++i) {
    cout << "Hello " << names[length - 1 - i] << endl;
  }
}

void lazyGreet(vector<string> names, int threshold) {
  int length = names.size();
  if (length < threshold) {
    greatEach(names);
  } else {
    cout << "Hello people!" << endl;
  }
}

void lazyGreet2(vector<string> names, int threshold, bool goodMood) {
  int length = names.size();
  if (length < threshold && goodMood) {
    greatEach(names);
  }
  // Else nothing
}

void lazyGreet3(vector<string> names, int threshold, bool goodMood) {
  int length = names.size();
  if (length < threshold || goodMood) {
    greatEach(names);
  }
}

void lazyGreet4(vector<string> names, int threshold) {
  int length = names.size();
  for (int i = 0; i < length; ++i) {
    if (i % 2 == 0) {
      cout << "Hello " << names[i] << endl;
    }
  }
}

int addition(int a, int b) {
  int resultat = a + b;
  return resultat;
}

int main() {
  cout << "Hello world" << endl;
  cout << "Hello you!" << endl;

  int nbPeople = 3;
  cout << nbPeople << endl;

  nbPeople = nbPeople + 1;
  //++nbPeople;
  cout << nbPeople << endl;

  int r = 5 + 2; // 7
  r = 5 - 2; // 3
  r = 5 * 2; // 10
  r = 5 / 2; // 2
  r = 5 % 2; // 1

  string greetings = "hello";
  string target = "you";
  cout << greetings << " " << target << endl;
  cout << greetings + " " + target << endl;

  for (int i = 0; i < nbPeople; ++i) {
    cout << "Hello you" << endl;
    cout << i << endl;
  }

  vector<string> names;
  names.push_back("Annie");
  names.push_back("Brandon");
  names.push_back("Caitlyn");
  names.push_back("Darius");
  //vector<string> names { "Annie", "Brandon", "Caitlyn", "Darius" };

  for (string name : names) {
    cout << "Hello " + name << endl;
  }

  manners();

  greatEach(names);

  // Creation de la fonction addName ci-dessus

  addName(names, nbPeople, "Elise");
  greatEach(names);
  cout << nbPeople << endl;
  addName(names, nbPeople, "Fiora");
  greatEach(names);
  cout << nbPeople << endl;

  greatEachInverse(names);

  lazyGreet(names, 10);
  lazyGreet(names, 2);

  bool goodMood = true;
  lazyGreet2(names, 7, goodMood);
  lazyGreet3(names, 7, goodMood);
  lazyGreet4(names, 7);


  // While there are more than 0 people in names
  while (names.size() > 0) {
    // Remove a name
    names.pop_back();
  }
  cout << names.size() << endl;

  int fiveAndNine = addition(5, 9);
  cout << fiveAndNine << endl;

  return 0;
}

