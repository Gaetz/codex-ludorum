#include "raylib.h"
#include <string>

using namespace std;

// Declarations
//----------------------------------------------------------------------------------
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

string description = "Writing an adventure game.";

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

