#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Inimigo.h"
#include "Nave.h"

class Tiros
{
public:
	int navex, navey;
	int inimx, inimy;
	int speed = 10;
	int contador = 1;
	bool naveTiroOn;
	bool inimTiroOn1, inimTiroOn2, inimTiroOn3, inimTiroOn4;

	SDL_Texture* tex_tiro1;
	SDL_Texture* tex_tiro;

	void NaveAtirar1(SDL_Renderer* r, int xI, int yI, bool &ini1On);
	void NaveAtirar2(SDL_Renderer* r, int xII, int yII, bool &ini2On);
	void NaveAtirar3(SDL_Renderer* r, int xIII, int yIII, bool &ini3On);
	void NaveAtirar4(SDL_Renderer* r, int xIV, int yIB, bool &ini4On);
	void ProcessInput(SDL_Event, int naveX, int naveY);
	void InimigoAtirar1(SDL_Renderer* r, int inimX, int inimY, bool &inimigo1On);
	void InimigoAtirar2(SDL_Renderer* r, int inimX, int inimY, bool &inimigo2On);
	void InimigoAtirar3(SDL_Renderer* r, int inimX, int inimY, bool &inimigo3On);
	void InimigoAtirar4(SDL_Renderer* r, int inimX, int inimY, bool &inimigo4On);
	void Update();
	void Died(int &estado, int naveX, int naveY);

	Inimigo inim;
	Nave nave;
	Tiros();
	~Tiros();
};

