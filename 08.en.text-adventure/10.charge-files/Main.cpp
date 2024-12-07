#include "raylib.h"
#include <string>

#include <fstream>
#include <sstream>

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
void changeState(string newState);

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
    changeState("debut");
}

// Update world
void update() {
    if (state == "debut") {
        if (IsKeyPressed(KEY_J)) {
            changeState("jump");
        }
        if (IsKeyPressed(KEY_H)) {
            changeState("cacher");
        }
    } else if (state == "jump") {
        if (IsKeyPressed(KEY_D)) {
            changeState("dagger");
        }
        if (IsKeyPressed(KEY_W)) {
            changeState("cacher");
        }
    } else if (state == "cacher") {
        if (IsKeyPressed(KEY_D)) {
            changeState("dagger");
        }
        if (IsKeyPressed(KEY_E)) {
            changeState("exit");
        }
        if (IsKeyPressed(KEY_P)) {
            changeState("push");
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

void changeState(string newState) {
    state = newState;
    description = changeDescription();
}


string changeDescription() {
    string path = "texts/" + state + ".txt";
    ifstream file { path };
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}