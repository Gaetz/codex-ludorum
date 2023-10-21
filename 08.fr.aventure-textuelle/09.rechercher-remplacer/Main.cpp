#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int LARGEUR_ECRAN = 800;
const int HAUTEUR_ECRAN = 450;

string description = "";
string etat = "debut";

void load();
void update();
void draw();
void unload();
string changerDescription();
void changerEtat(string nouvelEtat);

// Code
//----------------------------------------------------------------------------------
int main() {
    load();
    while (!WindowShouldClose()) {
        update();
        draw();
    }
    unload();
    return 0;
}


// Chargement du jeu
void load() {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "Aventure");
    SetTargetFPS(60);
    changerEtat("debut");
}

// Mise à jour de l'univers
void update() {
    if (etat == "debut") {
        if (IsKeyPressed(KEY_S)) {
            changerEtat("sauter");
        }
        if (IsKeyPressed(KEY_C)) {
            changerEtat("cacher");
        }
    } else if (etat == "sauter") {
        if (IsKeyPressed(KEY_D)) {
            changerEtat("dague");
        }
        if (IsKeyPressed(KEY_A)) {
            changerEtat("cacher");
        }
    } else if (etat == "cacher") {
        if (IsKeyPressed(KEY_D)) {
            changerEtat("dague");
        }
        if (IsKeyPressed(KEY_F)) {
            changerEtat("fuite");
        }
        if (IsKeyPressed(KEY_P)) {
            changerEtat("pousser");
        }
    }
}

// Dessin de l'univers
void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(description.c_str(), 50, 20, 20, WHITE); 

    EndDrawing();
}

// Déchargement du jeu
void unload() {
    CloseWindow();
}

void changerEtat(string nouvelEtat) {
    etat = nouvelEtat;
    description = changerDescription();
}


string changerDescription() {
    if (etat == "debut") {
        return
"Le magicien sort de l'ombre. Il jette sur vous un regard\n"
"méprisant et ses doigts se crispent sur la sphère\n" 
"crépitante qu'il tient à la main.\n"
"- Vous introduire dans ma tour aura été votre dernière\n"
"erreur, apprenti.\n"
"Sa voix semble étrangement lointaine et ses yeux sont\n"
"révulsés dans ses orbites. Vous comprenez avec horreur\n" 
"qu'il invoquait un sortilège mortel tandis qu'il vous\n" 
"parlait. Vous n'avez qu'un instant pour réagir !\n\n"
"S - Sauter sur le côté\n"
"C - Vous cacher derrière un meuble\n"
;
    } else if (etat == "sauter") {
        return
"Vous sautez sur le côté au moment où le sortilège se\n"
"déclenche. L'énergie magique vient exploser à l'endroit\n"
"où vous vous trouviez l'instant précédent. Vous courrez\n"
"pour mettre un peu de distance entre le magicien et vous.\n"
"Vous avisez une dague posée sur un bureau plus loin\n"
"et une grosse armoire derrière laquelle vous pourriez\n"
"vous cacher.\n\n"
"D - Aller ramasser la dague\n"
"A - Vous cacher derrière l'armoire\n" 
;
    } else if (etat == "cacher") {
        return 
"Vous vous accroupissez derrière la plus grande armoire\n"
"du laboratoire. Malgré l'épaisseur du bois, le sort\n"
"du magicien vous secoue quand il s'écrase contre\n"
"le meuble massif. Vous l'entendez s'approcher derrière\n"
"l'armoire en psalmodiant. Il prépare un nouveau sort!\n"
"Paniqué, vous regardez autour de vous. Vous yeux sont\n"
"attirée par l'éclat d'une dague serties de pierres\n"
"précieuses, posée parmi un tas de bijoux. Vous reperez\n"
"aussi la porte de sortie du laboratoire. Enfin, une\n"
"idée germe dans votre tête.\n\n" 
"D - Aller ramasser la dague\n"
"F - Foncer vers la sortie\n"
"P - Pousser l'armoire sur le magicien\n"
;
    } else {
        return "";
	}
}