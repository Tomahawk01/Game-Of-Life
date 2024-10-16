#include "Simulation.h"

Simulation::Simulation(int width, int height, int cellSize)
	: m_Grid{ width, height, cellSize },
	m_TempGrid{ width, height, cellSize },
	m_Running{ false }
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

void Simulation::Update()
{
	if (IsRunning())
	{
		for (int row = 0; row < m_Grid.GetRows(); row++)
		{
			for (int column = 0; column < m_Grid.GetColumns(); column++)
			{
				int liveNeighbors = CountLiveNeighbors(row, column);
				int cellValue = m_Grid.GetValue(row, column);

				if (cellValue == 1)
				{
					if (liveNeighbors > 3 || liveNeighbors < 2)
						m_TempGrid.SetValue(row, column, 0);
					else
						m_TempGrid.SetValue(row, column, 1);
				}
				else
				{
					if (liveNeighbors == 3)
						m_TempGrid.SetValue(row, column, 1);
					else
						m_TempGrid.SetValue(row, column, 0);
				}
			}
		}

		m_Grid = m_TempGrid;
	}
}

void Simulation::ClearGrid()
{
	if (!IsRunning())
		m_Grid.Clear();
}

void Simulation::CreateRandomState()
{
	if (!IsRunning())
		m_Grid.FillRandom();
}

void Simulation::ToggleCell(int row, int column)
{
	if (!IsRunning())
		m_Grid.ToggleCell(row, column);
}
