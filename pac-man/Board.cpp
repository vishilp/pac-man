#include "Board.h"

bool Board::isValidMove(PacMan* pac)
{
	int dir = pac->getDirection();
	if (dir == RIGHT)
	{
		if (board1[pac->Row()][pac->Col() + 1] == 46)
			return true;
	}
	return false;
}

void Board::movePacMan(int dir, int row, int col)
{

	if (dir == RIGHT)
	{
		board1[row][col] = 45;
		board1[row][col+1] = PACMAN;
	}
		return;
}

