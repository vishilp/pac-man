#include "Board.h"

bool Board::isValidMove(PacMan* pac)
{
	int dir = pac->getDirection();
	if (dir == RIGHT)
	{
		if (board1[pac->Row()][pac->Col() + 1] >= 45)
			return true;
	}
	if (dir == LEFT)
	{
		if (board1[pac->Row()][pac->Col() - 1] >= 45)
			return true;
	}
	if (dir == UP)
	{
		if (board1[pac->Row()-1][pac->Col()] >= 45)
			return true;
	}
	if (dir == DOWN)
	{
		if (board1[pac->Row() + 1][pac->Col()] >= 45)
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
	if (dir == LEFT)
	{
		board1[row][col] = 45; //set tile that pacman was on to empty
		temp = board1[row][col - 1];
		board1[row][col - 1] = PACMAN;
	}
	if (dir == UP)
	{
		board1[row][col] = 45; //set tile that pacman was on to empty
		temp = board1[row-1][col];
		board1[row-1][col] = PACMAN;
	}
	if (dir == DOWN)
	{
		board1[row][col] = 45; //set tile that pacman was on to empty
		temp = board1[row + 1][col];
		board1[row + 1][col] = PACMAN;
	}
	
	
	return temp;
}

