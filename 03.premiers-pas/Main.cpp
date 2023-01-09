#include <iostream>
#include <string>
#include <vector>

using namespace std;

void politesses() {
  cout << "Salut." << endl;
  cout << "Tu vas bien ?" << endl;
  cout << "Quel beau temps aujourd'hui !" << endl;
}

void saluerChacun(vector<string> noms) {
  for (string nom : noms) {
    cout << "Salut " << nom << endl;
  }
}

void ajouterNom(vector<string>& noms, int& nbPersonne, string nom) {
  noms.push_back(nom);
  nbPersonne = noms.size();
}

void saluerChacunInverse(vector<string> noms) {
  int longueur = noms.size();
  for (int i = 0; i < longueur; ++i) {
    cout << "Hello " << noms[longueur - 1 - i] << endl;
  }
}

void salutationParesseuse(vector<string> noms, int seuil) {
  int longueur = noms.size();
  if (longueur < seuil) {
    saluerChacun(noms);
  } else {
    cout << "Bonjour les gens !" << endl;
  }
}

void salutationParesseuse2(vector<string> noms, int seuil, bool bonneHumeur) {
  int longueur = noms.size();
  if (longueur < seuil && bonneHumeur) {
    saluerChacun(noms);
  }
  // Sinon rien
}

void salutationParesseuse3(vector<string> noms, int seuil, bool bonneHumeur) {
  int longueur = noms.size();
  if (longueur < seuil || bonneHumeur) {
    saluerChacun(noms);
  }
}

void salutationParesseuse4(vector<string> noms, int seuil) {
  int longueur = noms.size();
  for (int i = 0; i < longueur; ++i) {
    if (i % 2 == 0) {
      cout << "Bonjour " << noms[i] << endl;
    }
  }
}

int addition(int a, int b) {
  int resultat = a + b;
  return resultat;
}

int main() {
  cout << "Hello world" << endl;
  cout << "Salut toi !" << endl;

  int nbPersonne = 3;
  cout << nbPersonne << endl;

  nbPersonne = nbPersonne + 1;
  //++nbPersonne;
  cout << nbPersonne << endl;

  int r = 5 + 2; // 7
  r = 5 - 2; // 3
  r = 5 * 2; // 10
  r = 5 / 2; // 2
  r = 5 % 2; // 1

  string salutations = "hello";
  string cible = "you";
  cout << salutations << " " << cible << endl;
  cout << salutations + " " + cible << endl;

  for (int i = 0; i < nbPersonne; ++i) {
    cout << "Salut toi" << endl;
    cout << i << endl;
  }

  vector<string> noms;
  noms.push_back("Annie");
  noms.push_back("Brandon");
  noms.push_back("Caitlyn");
  noms.push_back("Darius");
  //vector<string> noms { "Annie", "Brandon", "Caitlyn", "Darius" };

  for (string nom : noms) {
    cout << "Salut " + nom << endl;
  }

  politesses();

  saluerChacun(noms);

  // Creation de la fonction ajouterNom ci-dessus

  ajouterNom(noms, nbPersonne, "Elise");
  saluerChacun(noms);
  cout << nbPersonne << endl;
  ajouterNom(noms, nbPersonne, "Fiora");
  saluerChacun(noms);
  cout << nbPersonne << endl;

  saluerChacunInverse(noms);

  salutationParesseuse(noms, 10);
  salutationParesseuse(noms, 2);

  bool bonneHumeur = true;
  salutationParesseuse2(noms, 7, bonneHumeur);
  salutationParesseuse3(noms, 7, bonneHumeur);
  salutationParesseuse4(noms, 7);


  // Tant qu’il y a plus de 0 personnes dans noms
	while (noms.size() > 0) {
		// Supprimer un nom
		noms.pop_back();
	}
  cout << noms.size() << endl;

  int cinqEtNeuf = addition(5, 9);
  cout << cinqEtNeuf << endl;

  return 0;
}

