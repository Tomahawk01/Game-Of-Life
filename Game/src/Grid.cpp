#include "Grid.h"

#include <raylib.h>

Grid::Grid(int Width, int Height, int CellSize)
	: m_Rows{ Height / CellSize },
	m_Columns{ Width / CellSize },
	m_CellSize{ CellSize },
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

void Grid::SetValue(int Row, int Column, int Value)
{
	if (Row >= 0 && Row < m_Rows &&
		Column >= 0 && Column < m_Columns)
	{
		m_Cells[Row][Column] = Value;
	}
}
