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
	void ClearGrid();
	void CreateRandomState();
	void ToggleCell(int row, int column);

	inline const bool IsRunning() const { return m_Running; }
	inline const void Start() { m_Running = true; }
	inline const void Stop() { m_Running = false; }

private:
	Grid m_Grid;
	Grid m_TempGrid;

	bool m_Running;
};
