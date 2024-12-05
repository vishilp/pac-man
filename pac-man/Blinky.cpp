#include "Blinky.h"

void Blinky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnBlinkyRect(), &location);
}

void Blinky::updateGhost()
{
	if (isOnPacMan())
	{
		player->setDead();
		return;
	}
	if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
	{
		updateRowsorCols();
		moving = false;
	}
	if (moving) {
		moveGhost();
		renderGhost();
	}
	else {
		moving = true;
		NodeManager manager;
		Node Blinky(getRow(), getCol());
		Node Pac(player->Row(), player->Col());
		if (chaseMode() && !isOnPacMan())
		{
			std::vector<Node> nodes = findPath(map, Blinky, Pac, &manager);
			if (!nodes.empty())
				translateNodeToDir(nodes[0]);
			moveGhost();
			renderGhost();
			if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) {
				updateRowsorCols();
				moving = false;
			}
		}
	}

}

