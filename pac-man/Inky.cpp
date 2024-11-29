#include "Inky.h"

void Inky::renderGhost()
{
	SDL_Rect location = { pixelX(), pixelY(), TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	SDL_RenderCopy(ren, sprites, TextureManager::ReturnInkyRect(), &location);
}

void Inky::updateGhost()
{

}