#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Nave
{
private:

public:
	Nave();
	~Nave();
	int x = 200, y = 500;
	int speed = 10;
	bool naveViva = true;
	bool anima��oOn;

	void Draw(SDL_Renderer* r);
	void Movimenta��o(SDL_Event);

	SDL_Texture* tex_Nave;
	SDL_Texture* tex_Nave1;

};

