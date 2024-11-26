#include "Ghost.h"

Ghost::Ghost(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* p, Board* board)
{
	alive = true;
	row = r;
	col = c;
	pixelx = col * 16;
	pixely = row * 16;
	direction = 0;
	ren = renderer;
	sprites = spritesheet;
	player = p;
	map = board;
}
bool Ghost::isAlive() { return alive; }
int Ghost::getRow() { return row; }
int Ghost::getCol() { return col; }
void Ghost::setRow(int r) { row = r; }
void Ghost::setCol(int c) { col = c; }

void Ghost::updateRowsorCols(int dir)
{
	if (dir == RIGHT)
		col += 1;
	if (dir == LEFT)
		col -= 1;
	if (dir == UP)
		row -= 1;
	if (dir == DOWN)
		row += 1;
}

bool Ghost::isOnPacMan()
{
	//check through pixel values instead
	if (row == player->Row() && col == player->Col())
		return true;
	return false;
}

void Ghost::moveGhost()
{
	pixelx *= 10; 
	pixely *= 10;
	if (direction == RIGHT)
		pixelx += speed;
	if (direction == LEFT)
		pixelx -= speed;
	if (direction == UP)
		pixely -= speed;
	if (direction == DOWN)
		pixely += speed;
	pixelx /= 10;
	pixely /= 10;
}

void Ghost::translateNodeToDir(Node node)
{
	int r = getRow();
	int c = getCol();

	if (node.row == r)  //if rows are same, clearly the ghost needs to move through cols
	{
		if (node.col == c + 1) {
			setDirection(RIGHT);
			return;
		}
		if (node.col == c - 1) {
			setDirection(LEFT);
			return;
		}

	}

	else
	{
		if (node.row == r + 1) {
			setDirection(DOWN);
			return;
		}
		if (node.row == r - 1) {
			setDirection(UP);
			return;
		}
	}
}
