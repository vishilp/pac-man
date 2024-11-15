#include "TextureManager.h"



SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(file);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return text;
}


SDL_Rect* TextureManager::ReturnSpriteRect(char c)
{
	SDL_Rect rect;
	switch (c)
	{
		case 'r':
			rect = { 18, 54, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
			return &rect;
		case '#':
			rect = { 180, 54, TextureManager::SpriteWidth, TextureManager::SpriteHeight };
			return &rect;
	}
}