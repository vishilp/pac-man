#include "Blinky.h"

void Blinky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnBlinkyRect(), &location);
}

void Blinky::updateGhost()
{
	if (isOnPacMan())
		return;
	NodeManager manager;
	Node Blinky(getRow(), getCol());
	Node Pac(player->Row(), player->Col());
	if (chaseMode())
	{
		std::vector<Node> nodes = findPath(map, Blinky, Pac, &manager);
		translateNodeToDir(nodes[0]);
		moveGhost();
		renderGhost();
		if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0))
			updateRowsorCols(getDirection());
	}
}

