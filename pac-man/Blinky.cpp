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
	Node Blinky(getRow(), getCol());
	Node Pac(player->Row(), player->Col());
	if (chaseMode())
	{
		std::vector<Node> nodes = findPath(map, Blinky, Pac);
		Node first = nodes[0];
		setRow(first.row);
		setCol(first.col);
	}
}