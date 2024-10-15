#include "Grid.h"

#include <raylib.h>

#include <utility>

Grid::Grid(int width, int height, int cellSize)
	: m_Rows{ height / cellSize },
	m_Columns{ width / cellSize },
	m_CellSize{ cellSize },
	m_Cells(m_Rows, std::vector<int>(m_Columns, 0))
{}

void Grid::Draw()
{
	for (int row = 0; row < m_Rows; row++)
	{
		for (int column = 0; column < m_Columns; column++)
		{
			Color color = m_Cells[row][column] ? Color{ 0, 255, 0, 255 } : Color{ 70, 70, 70, 255 };
			DrawRectangle(column * m_CellSize, row * m_CellSize, m_CellSize - 1, m_CellSize - 1, color);
		}
	}
}

void Grid::SetValue(int row, int column, int value)
{
	if (IsWithinBounds(row, column))
	{
		m_Cells[row][column] = value;
	}
}

int Grid::GetValue(int row, int column)
{
	if (IsWithinBounds(row, column))
	{
		return m_Cells[row][column];
	}

	return 0;
}

bool Grid::IsWithinBounds(int row, int column)
{
	if (row >= 0 && row < m_Rows &&
		column >= 0 && column < m_Columns)
	{
		return true;
	}

	return false;
}
