#pragma once

#include "Grid.h"

class Simulation
{
public:
	Simulation(int width, int height, int cellSize);

	void Draw();
	void SetCellValue(int row, int column, int value);
	int CountLiveNeighbors(int row, int column);
	void Update();

private:
	Grid m_Grid;
	Grid m_TempGrid;
};
