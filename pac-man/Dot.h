#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Dot  //inherit from consumables
{
	public:
		Dot(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect* sprite, SDL_Rect* dest);
		~Dot();

};
