#include <raylib.h>

#include "Grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 15

#define CELL_SIZE 25

int main()
{
	Color clearColor = { 50, 50, 50, 255 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	Grid grid{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };
	grid.SetValue(10, 1, 1);
	grid.SetValue(3, 12, 1);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(clearColor);
		grid.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
