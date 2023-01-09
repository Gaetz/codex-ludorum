#include "raylib.h"
#include <string>

using namespace std;

string texte = "Salut Raylib !";

void draw() {
  BeginDrawing();
  DrawText(texte.c_str(), 190, 200, 20, BLUE);
  EndDrawing();
}

int main() {
  InitWindow(800, 450, "Interaction");

  while(!WindowShouldClose()) {
    draw();
  }

  CloseWindow();
  return 0;
}