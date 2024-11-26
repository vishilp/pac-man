#include "Pinky.h"

void Pinky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnPinkyRect(), &location);
}

void Pinky::updateGhost()
{
	if (isOnPacMan())
		return;

	NodeManager manager;
	Node Pinky(getRow(), getCol());
	Node Pac;

	int dir = player->getDirection();
	switch (dir)
	{
		case 0: //if no direction at start of game, dont move
			return;
		case 1: //left; keep checking to see if move is possible until you get to pacman, at which point get to his tile
			for (int i = 4; i >= 0; i--)
			{
				if (map->isValidPinkyMove(player->Row(), player->Col() - i)) {
					Pac.row = player->Row();
					Pac.col = player->Col() - i;
					break;
				}
			}
			break;
		case 2: //right
			for (int i = 4; i >= 0; i--)
			{
				if (map->isValidPinkyMove(player->Row(), player->Col() + i)) {
					Pac.row = player->Row();
					Pac.col = player->Col() + i;
					break;
				}
			}
			break;
		case 3: //up
			for (int i = 4; i >= 0; i--)
			{
				if (map->isValidPinkyMove(player->Row() - i, player->Col())) {
					Pac.row = player->Row() -i;
					Pac.col = player->Col();
					break;
				}
			}
			break;
		case 4: //down
			for (int i = 4; i >= 0; i--)
			{
				if (map->isValidPinkyMove(player->Row() + i, player->Col())) {
					Pac.row = player->Row() + i;
					Pac.col = player->Col();
					break;
				}
			}
			break;
	}
	if (chaseMode())
	{
		std::vector<Node> nodes = findPath(map, Pinky, Pac, &manager);
		if (!nodes.empty())
			translateNodeToDir(nodes[0]);
		moveGhost();
		renderGhost();
		if ((fmod(pixelX(), 16.0) == 0) && (fmod(pixelY(), 16.0) == 0)) ///only change direction when completely on a cell
			updateRowsorCols();
	}
}