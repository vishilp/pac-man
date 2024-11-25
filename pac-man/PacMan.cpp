#include "PacMan.h"

PacMan::PacMan(int r, int c, SDL_Renderer* renderer, SDL_Texture* spritesheet)
{
	row = r;
	col = c;
	pixelx = col * 16;
	pixely = row * 16;
	direction = 0;
	ren = renderer;
	sprites = spritesheet;
	queuedDirection = 0;
	queuedFrames = 0;
}

void PacMan::setQueuedDirection(int dir)
{
	queuedDirection = dir;
	queuedFrames = 0;
}

void PacMan::setDirection()
{
	if (direction == 0) //for start of game
	{
		direction = queuedDirection;
		queuedDirection = 0;
		queuedFrames = 0;
		return;
	}
	if (queuedFrames > 16 || queuedDirection ==0) { // 16frames of leeway, should be about 16 pixels (pacman moves 1 pixel per iteration)
		queuedDirection = 0;
		queuedFrames = 0;
		return;
	}

	if (direction == RIGHT || direction == LEFT)
	{
		if (queuedDirection == RIGHT || queuedDirection == LEFT) //IF ALREADY MOVING ALONG X AXIS, ALLOW DIR SWAP IN X AXIS
		{
			direction = queuedDirection;
			queuedDirection = 0;
			queuedFrames = 0;
			return;
		}
		else
		{
			if (fmod(pixelx, 16.0) == 0) {
				direction = queuedDirection;
				queuedDirection = 0;
				queuedFrames = 0;
				return;
			}
		}
	}
	if (direction == UP || direction == DOWN)
	{
		if (queuedDirection == UP || queuedDirection == DOWN) //IF ALREADY MOVING ALONG Y AXIS, ALLOW DIR SWAP IN X AXIS
		{
			direction = queuedDirection;
			queuedDirection = 0;
			queuedFrames = 0;
			return;
		}
		else
		{
			if (fmod(pixely, 16.0) == 0)
			{
				direction = queuedDirection;
				queuedDirection = 0;
				queuedFrames = 0;
				return;
			}
		}
	}

	queuedFrames++;  //if not valid move atm, increase queue frame number

}

int PacMan::getDirection()
{
	return direction;
}

void PacMan::movePacMan(int dir)
{
	if (dir == RIGHT)
		pixelx += pacSpeed;
	if (dir == LEFT)
		pixelx-= pacSpeed;
	if (dir == UP)
		pixely-= pacSpeed;
	if (dir == DOWN)
		pixely+= pacSpeed;
}

/*void PacMan::updateRowsorCols(int dir)
{
	if (dir == RIGHT)
		col += 1;
	if (dir == LEFT)
		col -= 1;
	if (dir == UP)
		row-= 1;
	if (dir == DOWN)
		row += 1;
} */ 

bool PacMan::updateRowsorCols()
{
	int c = col;
	int r = row;
	if (fmod(pixelx, 16.0) == 0)
		col = pixelx / 16;
	if (fmod(pixely, 16.0) == 0)
		row = pixely / 16;
	if (r != row || c != col) //if old row/col was different, we updated them
		return true;
	
	return false;
}

void PacMan::renderPacMan()
{
	SDL_Rect spawnpoint = { pixelx, pixely, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnPacmanRect(), &spawnpoint);
}

PacMan::~PacMan()
{

}

