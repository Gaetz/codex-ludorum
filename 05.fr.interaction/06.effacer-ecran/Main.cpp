#include "raylib.h"
#include <string>

using namespace std;

string texte = "Salut Raylib !";

void update() {
  if (IsKeyPressed(KEY_C)) {
    texte = "Ca va ?";
  }
}

void draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText(texte.c_str(), 190, 200, 20, BLUE);
  EndDrawing();
}

int main() {
  InitWindow(800, 450, "Interaction");

  while(!WindowShouldClose()) {
    update();
    draw();
  }

  CloseWindow();
  return 0;
}