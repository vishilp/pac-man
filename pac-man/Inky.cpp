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
	if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
	{
		updateRowsorCols();
		moving = false;
	}
	if (moving) {
		moveGhost();
		renderGhost();
	}
	if (nodes.empty()) { //go to endpoint before running A* again
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
		default:   // just follow pacman's current tile
		}

		int rowvector = row - blinky->getRow();  //vectors from blinky's position to "ahead" tile, and then doubled
		int colvector = blinky->getCol();

		
	}
}