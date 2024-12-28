#include <iostream>
#include <string>
#include <vector>

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

void afficherLigne(int ligne, 
                   string premiereCase, 
                   string deuxiemeCase, 
                   string troisiemeCase) {
  // Formater le contenu des cases
  if (premiereCase == "") {
    premiereCase = to_string(ligne * 3 + 1);
  }
  if (deuxiemeCase == "") {
    deuxiemeCase = to_string(ligne * 3 + 2);
  }
  if (troisiemeCase == "") {
    troisiemeCase = to_string(ligne * 3 + 3);
  }
  // Construire la ligne format texte
  string ligneTexte = " " + premiereCase + " | " + deuxiemeCase + " | " + troisiemeCase;
  // Afficher la ligne construite
  cout << ligneTexte << endl;
}

void afficherTrait() {
  cout << "-----------" << endl;
}

void afficherPlateau(vector<string> plateau) {
  // Pour chaque ligne
  for(int i = 0; i < 3; ++i) {
    // Afficher la ligne
    afficherLigne(i, plateau[i * 3], plateau[i * 3 + 1], plateau[i * 3 + 2]);
    // Afficher des traits si ce n'est pas la dernière ligne
    if (i < 2) {
      afficherTrait();
    }
  }
}

bool egalite(vector<string> plateau) {
	return false;
}

bool verifierVictoire(string jeton, vector<string> plateau) {
  // Lignes
  if (plateau[0] == jeton && plateau[1] == jeton && plateau[2] == jeton) {
    return true; 
  }
  if (plateau[3] == jeton && plateau[4] == jeton && plateau[5] == jeton) {
    return true; 
  }
  if (plateau[6] == jeton && plateau[7] == jeton && plateau[8] == jeton) {
    return true; 
  }
  // Colonnes
  if (plateau[0] == jeton && plateau[3] == jeton && plateau[6] == jeton) {
    return true; 
  }
  if (plateau[1] == jeton && plateau[4] == jeton && plateau[7] == jeton) {
    return true; 
  }
  if (plateau[2] == jeton && plateau[5] == jeton && plateau[8] == jeton) {
    return true; 
  }
  // Diagonales
  if (plateau[0] == jeton && plateau[4] == jeton && plateau[8] == jeton) {
    return true; 
  }
  if (plateau[2] == jeton && plateau[4] == jeton && plateau[6] == jeton) {
    return true; 
  }
  
  return false;
}

void feliciter(bool victoireJ1, bool victoireJ2) {
  cout << endl;
  cout << "* * * * * * * * * * * *" << endl;
  if (victoireJ1) {
    cout << "* Le joueur 1 gagne ! *" << endl;
  } else if (victoireJ2) {
    cout << "* Le joueur 2 gagne ! *" << endl;
  }	else {
    cout << "*      Egalité !      *" << endl;
  }
  cout << "* * * * * * * * * * * *" << endl;
}

int main() {
  // Afficher le titre
  afficherTitre();
  // Afficher les règles du jeu
  afficherRegles();
  // Afficher le plateau
  vector<string> plateau { "", "", "", "", "", "", "", "", "" };
  afficherPlateau(plateau);
  // Mettre les booléens victoireJ1 et victoireJ2 à faux
  bool victoireJ1 = false;
	bool victoireJ2 = false;
    
  // Tant que le jeu n'est pas fini (victoireJ1 et victoireJ2 faux)
  // et qu'il n'y a pas égalité
  while ( !victoireJ1 && !victoireJ2 && !egalite(plateau) ) {
    // Demander au joueur 1 son coup
    // - Récupérer le coup sous forme de string
    cout << endl;
    cout << "Joueur 1 : entrez un chiffre entre 1 et 9:";
    int caseChoisie;
    cin >> caseChoisie;
    // - Vérifier si le joueur abandonne
    if (caseChoisie == 0) {
      victoireJ2 = true;
    }
    // - Modifier le plateau si la case choisie est valide
    if (caseChoisie >= 1 && caseChoisie <= 9
        && plateau[caseChoisie - 1] != "X" && plateau[caseChoisie - 1] != "O") {
      plateau[caseChoisie - 1] = "O";
    }
    // Afficher le plateau mis à jour
    afficherPlateau(plateau);
    // Vérifier si le joueur 1 gagne, mettre à jour victoireJ1
    victoireJ1 = verifierVictoire("O", plateau);
    // Si le joueur 1 n'a pas gagné et pas d'égalite
    if ( !victoireJ1 && !egalite(plateau) ) {
      // Demander au joueur 2 son coup
      cout << endl;
      cout << "Joueur 2 : entrez un chiffre entre 1 et 9:";
      cin >> caseChoisie;
      if (caseChoisie == 0) {
        victoireJ1 = true;
      }
      if (caseChoisie >= 1 && caseChoisie <= 9
          && plateau[caseChoisie - 1] != "X" && plateau[caseChoisie - 1] != "O") {
        plateau[caseChoisie - 1] = "X";
      }
      // Afficher le plateau mis à jour
      afficherPlateau(plateau);
      // Vérifier si le joueur 2 gagne, maj victoireJ2
      victoireJ2 = verifierVictoire("X", plateau);
    }
  }
  // Afficher un message pour féliciter le joueur victorieux
  feliciter(victoireJ1, victoireJ2);
  
  return 0;
}