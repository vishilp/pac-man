#include "Board.h"

void Board::movePacMan(int dir, int row, int col)
{

	if (dir == RIGHT)
	{
		board1[row][col] = 45;
		board1[row][col+1] = PACMAN;
	}
		return;
}