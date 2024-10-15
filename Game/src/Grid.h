#pragma once

#include <vector>

class Grid
{
public:
	Grid(int Width, int Height, int CellSize);

	void Draw();
	void SetValue(int Row, int Column, int Value);

private:
	int m_Rows;
	int m_Columns;
	int m_CellSize;

	std::vector<std::vector<int>> m_Cells;
};
