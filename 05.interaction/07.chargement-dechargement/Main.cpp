#include "raylib.h"
#include <string>

using namespace std;

string texte = "Salut Raylib !";

void load() {
  InitWindow(800, 450, "Interaction");
  SetTargetFPS(60);
}

void update() {
  if (IsKeyPressed(KEY_C)) {
    texte = "Ca va ?";
  }
}

void draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText(texte.c_str(), 190, 200, 20, MAGENTA);
  EndDrawing();
}

void unload() {
  CloseWindow();
}

int main() {
  load();

  while(!WindowShouldClose()) {
    update();
    draw();
  }

  unload();
  return 0;
}