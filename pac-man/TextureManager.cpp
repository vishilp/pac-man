#include "TextureManager.h"



SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(file);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return text;
}


SDL_Rect* TextureManager::ReturnSpriteRect(int id)
{
	SDL_Rect rect;
	int x = 0;
	int y = 0;
	int temp = 0;

	if (id > 48) //render black board
		id = 45;

	if (id < 17)
	{
		x = (2 * (id - 1)) + (16 * (id - 1));
		y = 0;
		rect = { x, y, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
		return &rect;
	}
	if (id < 33)
	{
		y = 18;
		temp = id - 16;
		x= (2 * (temp - 1)) + (16 * (temp - 1));
		rect = { x, y, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
		return &rect;
	}
	else
	{
		y = 36;
		temp = id - 32;
		x = (2 * (temp - 1)) + (16 * (temp - 1));
		rect = { x, y, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
		return &rect;
	}
}

SDL_Rect* TextureManager::ReturnPacmanRect()
{
	SDL_Rect rect = { 0, 0, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}

SDL_Rect* TextureManager::ReturnBlinkyRect()
{
	SDL_Rect rect = { 2, 62, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}

SDL_Rect* TextureManager::ReturnPinkyRect()
{
	SDL_Rect rect = { 2, 80, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}

SDL_Rect* TextureManager::ReturnInkyRect()
{
	SDL_Rect rect = { 2, 96, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}

SDL_Rect* TextureManager::ReturnClydeRect()
{
	SDL_Rect rect = { 2, 112, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}

SDL_Rect* TextureManager::ReturnScaredGhost()
{
	SDL_Rect rect = { 130, 62, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
	return &rect;
}



