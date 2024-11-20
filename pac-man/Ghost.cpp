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
