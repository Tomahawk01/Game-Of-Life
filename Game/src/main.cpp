#include "Simulation.h"

#include <raylib.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define CELL_SIZE 10

int main()
{
	Color clearColor = { 50, 50, 50, 255 };
	int FPS = 10;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);
	SetExitKey(KEY_BACKSPACE);

	Simulation simulation{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };

	while (!WindowShouldClose())
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePos = GetMousePosition();
			int row = mousePos.y / CELL_SIZE;
			int column = mousePos.x / CELL_SIZE;

			simulation.ToggleCell(row, column);
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			simulation.Start();
			SetWindowTitle("Game of Life is running ...");
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			simulation.Stop();
			SetWindowTitle("Game of Life has stopped");
		}
		else if (IsKeyPressed(KEY_LEFT))
		{
			if (FPS > 3)
			{
				FPS--;
				SetTargetFPS(FPS);
			}
		}
		else if (IsKeyPressed(KEY_RIGHT))
		{
			FPS++;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_R))
		{
			simulation.CreateRandomState();
		}
		else if (IsKeyPressed(KEY_C))
		{
			simulation.ClearGrid();
		}

		simulation.Update();

		BeginDrawing();
		ClearBackground(clearColor);
		simulation.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
