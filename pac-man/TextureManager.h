#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Dot.h"

//Wall textures are 16x16 with 2pixels in between

class TextureManager
{
	public:
		static SDL_Texture* LoadTexture(const char* file, SDL_Renderer* renderer);
		//calling it static allows for it to be called without needing a texturemanager obj
		static SDL_Rect* ReturnSpriteRect(int id);
		static SDL_Rect* ReturnPacmanRect();
		static SDL_Rect* ReturnBlinkyRect();

		const static int SpriteHeight = 16;
		const static int SpriteWidth = 16;
};