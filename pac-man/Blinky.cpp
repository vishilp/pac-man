#include "Blinky.h"

void Blinky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnBlinkyRect(), &location);
}

void Blinky::updateGhost()
{

}