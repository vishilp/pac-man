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
}

void PacMan::setDirection(int dir)
{
	direction = dir;
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
	if (int(pixelx) % 16 == 0)
		col = pixelx / 16;  
	if (int(pixely) % 16 == 0)
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

