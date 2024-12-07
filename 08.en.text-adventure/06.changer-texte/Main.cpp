#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

string description = "";
string state = "start";

void load();
void update();
void draw();
void unload();
string changeDescription();

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
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Text Adventure");
    SetTargetFPS(60);
}

// Update world
void update() {
    if (state == "start") {
        description = changeDescription();
        if (IsKeyPressed(KEY_J)) {
            state = "jump";
        }
        if (IsKeyPressed(KEY_H)) {
            state = "hidden";
        }
    } else if (state == "jump") {
        description = changeDescription();
        if (IsKeyPressed(KEY_D)) {
            state = "dagger";
        }
        if (IsKeyPressed(KEY_W)) {
            state = "hidden";
        }
    } else if (state == "hidden") {
        description = changeDescription();
        if (IsKeyPressed(KEY_D)) {
            state = "dagger";
        }
        if (IsKeyPressed(KEY_E)) {
            state = "exit";
        }
        if (IsKeyPressed(KEY_P)) {
            state = "push";
        }
    }
}

// Draw world
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

string changeDescription() {
    if (state == "start") {
        return
"The wizard steps out of the shadows. He gives you a\n"
"contemptuous look and his fingers tighten on the\n"
"crackling sphere he holds in his hand.\n"
"- Entering my tower will be your last mistake, apprentice.\n"
"His voice seems strangely distant and his eyes are\n"
"rolled back in his sockets. You realize with horror\n"
"that he was invoking a deadly spell while he was\n"
"talking to you. You have only a moment to react!\n\n"
"J - Jump to the side\n"
"H - Hide behind a piece of furniture\n"
;
    } else if (state == "jump") {
        return
"You jump to the side just as the spell is cast. The \n"
"magical energy explodes where you were just a moment ago.\n"
"You run to put some distance between you and the wizard.\n"
"You notice a dagger lying on a desk further away\n"
"and a large wardrobe behind which you could hide.\n\n"
"D - Go pick up the dagger\n"
"W - Hide behind the wardrobe\n"
;
    } else if (state == "hidden") {
        return
"You crouch behind the largest wardrobe in the laboratory.\n"
"Despite the thickness of the wood, the wizard's spell shakes\n"
"you as it crashes against the massive piece of furniture.\n"
"You hear him approaching behind the wardrobe, chanting.\n"
"He is preparing a new spell!\n"
"Panicked, you look around. Your eyes are drawn to the glint\n"
"of a dagger set with precious stones, lying among a pile\n"
"of jewelry. You also spot the laboratory's exit door.\n"
"Finally, an idea forms in your mind.\n\n"
"D - Go pick up the dagger\n"
"E - Dash towards the exit\n"
"P - Push the wardrobe onto the wizard\n"
;
    } else {
        return "";
	}
}