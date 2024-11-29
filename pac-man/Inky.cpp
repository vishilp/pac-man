#include "Inky.h"

void Inky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnInkyRect(), &location);
}

void Inky::updateGhost()
{
	if (isOnPacMan())
		return;
	//finish his move before recalculating
	int dir = player->getDirection();
	int row = player->Row();
	int col = player->Col();

	switch (dir)
	{
	case 1:
		col -= 2;
		break;
	case 2:
		col += 2;
		break;
	case 3:
		row -= 2;
		break;
	case 4:
		row += 2;
		break;
	default:
		// just follow pacman's current tile
	}
	
	int blinkyrow = blinky->getRow();
	//backdrop of just target pacman?
}