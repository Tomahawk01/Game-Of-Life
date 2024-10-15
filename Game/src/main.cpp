#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 15

int main()
{
	Color clearColor = { 50, 50, 50, 255 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(clearColor);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
