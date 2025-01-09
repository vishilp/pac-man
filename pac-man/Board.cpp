#include "Board.h"

bool Board::isValidMove(PacMan* pac, int dir)
{


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


bool Board::isValidPinkyMove(int targetrow, int targetcol)
{
	if (targetrow < 0 || targetrow >= height)
		return false;
	if (targetcol < 0 || targetcol >= width)
		return false;
	
	if (board1[targetrow][targetcol] >= 45)
		return true;
	else
		return false;
}

std::vector<int> validScaredGhostMoves(int invaliddir, int row, int col, Board* map) {
	std::vector<int> dirlist;
	//do not allow opposing dirs, if moving left already, don't switch right
	for (int i = 1; i <= 4; i++)
	{
		if (i == invaliddir)
			continue;
		else if (i == RIGHT)
		{
			if ((col + 1 < 28) && (map->board1[row][col + 1] >= 45))
			{
				dirlist.push_back(RIGHT);
			}

		}

		else if (i == LEFT)
		{
			if ((col - 1 >= 0) && (map->board1[row][col - 1] >= 45))
			{
				dirlist.push_back(LEFT);
			}

		}

		else if (i == UP)
		{
			if ((row - 1 >= 0) && (map->board1[row-1][col] >= 45))
			{
				dirlist.push_back(UP);
			}

		}

		else if (i == DOWN)
		{
			if ((row + 1 < 31) && (map->board1[row + 1][col] >= 45))
			{
				dirlist.push_back(DOWN);
			}

		}

	}
	
	return dirlist;

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

