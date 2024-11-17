#include "Dot.h"

Dot::Dot(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect* sprite, SDL_Rect* dest)
{
	SDL_RenderCopy(ren, tex, sprite, dest);
}

Dot::~Dot()
{

}