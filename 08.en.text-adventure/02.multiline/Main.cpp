#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

string description =
"The wizard steps out of the shadows. He gives you a\n"
"contemptuous look and his fingers tighten on the\n"
"crackling sphere he holds in his hand.\n"
"- Entering my tower will be your last mistake, apprentice.\n"
"His voice seems strangely distant and his eyes are\n"
"rolled back in his sockets. You realize with horror\n"
"that he was invoking a deadly spell while he was\n"
"talking to you. You have only a moment to react!\n";

void load();
void update();
void draw();
void unload();

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

