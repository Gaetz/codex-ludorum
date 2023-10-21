#include "raylib.h"

void draw() {
  BeginDrawing();
  DrawText("Salut Raylib !", 190, 200, 20, BLUE);
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