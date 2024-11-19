#include "Board.h"

bool Board::isValidMove(PacMan* pac)
{
	int dir = pac->getDirection();
	if (dir == RIGHT)
	{
		if (board1[pac->Row()][pac->Col() + 1] >= 45)
			return true;
	}
	return false;
}

int Board::movePacMan(int dir, int row, int col)
{
	int temp = 0;
	if (dir == RIGHT)
	{
		board1[row][col] = 45; //set tile that pacman was on to empty
		temp = board1[row][col + 1];
		board1[row][col+1] = PACMAN;
	}
		return temp;
}

