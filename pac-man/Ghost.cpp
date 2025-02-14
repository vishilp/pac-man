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
	moving = false;
	blinky = nullptr;
}

Ghost::Ghost(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet, PacMan* p, Board* board, Ghost* Blinky)
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
	moving = false;
	blinky = Blinky;
}

bool Ghost::isAlive() { return alive; }
int Ghost::getRow() { return row; }
int Ghost::getCol() { return col; }
void Ghost::setRow(int r) { row = r; }
void Ghost::setCol(int c) { col = c; }

void Ghost::updateRowsorCols()
{
	col = pixelx / 16;
	row = pixely / 16;
}

bool Ghost::isOnPacMan()
{
	//check through pixel values instead
	if (pixelX() <= player->pixelX()+8 && (pixelX() >= player->pixelX() - 8))
		if (pixelY() <= player->pixelY() + 8 && (pixelY() >= player->pixelY() - 8))
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

void Ghost::setOppositeDirection() 
{
	switch (direction) {
	case (1):
		direction = 2;
		break;
	case (2):
		direction = 1;
		break;
	case (3):
		direction = 4;
		break;
	case (4):
		direction = 3;
		break;
	default: 
		break;
	}
}

int Ghost::getOppositeDirection()
{
	switch (direction) {
	case (1):
		return 2;
	case (2):
		return 1;
	case (3):
		return 4;
	case (4):
		return 3;
	default:
		break;
	}
}

void Ghost::updateScaredGhost() {
	
	if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
	{
		updateRowsorCols();
		std::vector<int> directions = map->validScaredGhostMoves(getOppositeDirection(), row, col, map);
		//cannot use opposing dirs unless no other option, e.g. if already moving left, don't switch right
		if (directions.empty())
			setOppositeDirection();

	}
	if (!scaredmoving) { //if scared mode just started
		setSpeed(4);	
		setOppositeDirection();
		moveGhost();
		renderGhost();
		scaredmoving = true;
	}
	else //if already moving in a direction, finish it
	{
		moveGhost();
		renderGhost();
	}
	return;
}
