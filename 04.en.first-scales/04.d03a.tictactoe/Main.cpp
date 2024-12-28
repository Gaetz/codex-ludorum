#include <iostream>
#include <string>

using namespace std;

void afficherTitre() {
  cout << "################################################" << endl;
  cout << "# Bienvenue dans Ultimate Terminal Tic-Tac-Toe #" << endl;
  cout << "################################################" << endl;
  cout << endl;
}


void afficherRegles() {
  cout << "Le plateau est divisé en 9 cases. Chaque joueur" << endl;
  cout << "place à tour de rôle son symbole (O ou X) dans" << endl;
  cout << "une des cases." << endl;
  cout << endl;
  cout << "Le premier joueur qui aligne 3 symboles, en ligne," << endl;
  cout << "en colonne ou en diagonale gagne la partie." << endl;
  cout << endl;
  cout << "Pour placer un symbole, il faut entrer le" << endl;
  cout << "numéro correspondant à la case sur laquelle on" << endl;
  cout << "souhaite jouer." << endl;
}

void afficherLigne(int ligne) {
  // Formater le contenu des cases
  string premiereCase = to_string(ligne * 3 + 1);
  string deuxiemeCase = to_string(ligne * 3 + 2);
  string troisiemeCase = to_string(ligne * 3 + 3);
  // Construire la ligne format texte
  string ligneTexte = " " + premiereCase + " | " + deuxiemeCase + " | " + troisiemeCase;
  // Afficher la ligne construite
  cout << ligneTexte << endl;
}

void afficherTrait() {
  cout << "-----------" << endl;
}

void afficherPlateau() {
  // Pour chaque ligne
  for(int i = 0; i < 3; ++i) {
    // Afficher la ligne
    afficherLigne(i);
    // Afficher des traits si ce n'est pas la dernière ligne
    if (i < 2) {
      afficherTrait();
    }
  }
}

int main() {
  // Afficher le titre
  afficherTitre();
  // Afficher les règles du jeu
  afficherRegles();
  // Afficher le plateau
  afficherPlateau();
  // Mettre les booléens victoireJ1 et victoireJ2 à faux
  
  // Tant que le jeu n'est pas fini (victoireJ1 et victoireJ2 faux)
  // et qu'il n'y a pas égalité
    // Demander au joueur 1 son coup
    // Afficher le plateau mis à jour
    // Vérifier si le joueur 1 gagne, mettre à jour victoireJ1
    // Si le joueur 1 n'a pas gagné et pas d'égalite
      // Demander au joueur 2 son coup
      // Afficher le plateau mis à jour
      // Vérifier si le joueur 2 gagne, maj victoireJ2
  
  // Afficher un message pour féliciter le joueur victorieux
  return 0;
}