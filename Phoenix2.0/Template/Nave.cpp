#include "Nave.h"


Nave::Nave()
{
}

Nave::~Nave()
{

}

void Nave::Draw(SDL_Renderer* r)
{
	if (naveViva == true)
	{
		SDL_Rect nave = { 0, 0, 32, 21 };
		SDL_Rect nave1 = { x, y, 40, 30 };
		SDL_RenderCopy(r, tex_Nave, &nave, &nave1);
	}
	//if (anima��oOn == true)
	//{
	//	SDL_Rect nave2 = { 0, 0, 24, 21 };
	//	SDL_Rect nave3 = { x , y, 40, 30 };
	//	SDL_RenderCopy(r, tex_Nave1, &nave2, &nave3);
	//}
}

void Nave::Movimenta��o(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_RIGHT)
		{
			x += speed;
			if (x >= 820)
			{
				x -= speed;
			}
		}
		else if (e.key.keysym.sym == SDLK_LEFT)
		{
			x -= speed;
			if (x <= 0)
			{
				x += speed;
			}
		}
	}
}