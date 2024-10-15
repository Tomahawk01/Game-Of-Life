#include "Simulation.h"

#include <raylib.h>

#include <iostream>

// NOTE: 32x32 grid
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define FPS 15

#define CELL_SIZE 25

int main()
{
	Color clearColor = { 50, 50, 50, 255 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	Simulation simulation{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };
	simulation.SetCellValue(5, 31, 1);
	simulation.SetCellValue(6, 0, 1);
	simulation.SetCellValue(5, 0, 1);
	simulation.SetCellValue(4, 0, 1);

	std::cout << simulation.CountLiveNeighbors(5, 31) << std::endl;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(clearColor);
		simulation.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
