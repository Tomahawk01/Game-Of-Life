#pragma once

#include <vector>

class Grid
{
public:
	Grid(int width, int height, int cellSize);

	void Draw();
	void SetValue(int row, int column, int value);
	int GetValue(int row, int column);
	bool IsWithinBounds(int row, int column);

	void FillRandom();
	void Clear();

	void ToggleCell(int row, int column);

	inline const int GetRows() const { return m_Rows; }
	inline const int GetColumns() const { return m_Columns; }

private:
	int m_Rows;
	int m_Columns;
	int m_CellSize;

	std::vector<std::vector<int>> m_Cells;
};
