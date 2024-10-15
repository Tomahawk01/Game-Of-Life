#include "Simulation.h"

Simulation::Simulation(int width, int height, int cellSize)
	: m_Grid{ width, height, cellSize }
{}

void Simulation::Draw()
{
	m_Grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
	m_Grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
	int liveNeighbors = 0;

	std::vector<std::pair<int, int>> neighborOffset =
	{
		{-1, 0},	// Above
		{1, 0},		// Below
		{0, -1},	// Left
		{0, 1},		// Right
		{-1, -1},	// Diagonal Upper Left
		{-1, 1},	// Diagonal Upper Right
		{1, -1},	// Diagonal Lower Left
		{1, 1},		// Diagonal Lower Right
	};

	for (const auto& offset : neighborOffset)
	{
		int neighborRow = (row + offset.first + m_Grid.GetRows()) % m_Grid.GetRows();
		int neighborColumn = (column + offset.second + m_Grid.GetColumns()) % m_Grid.GetColumns();

		liveNeighbors += m_Grid.GetValue(neighborRow, neighborColumn);
	}

	return liveNeighbors;
}
