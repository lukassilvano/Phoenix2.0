#include "Tiros.h"


Tiros::Tiros()
{
}


Tiros::~Tiros()
{
}
void Tiros::NaveAtirar1(SDL_Renderer* r, int xI, int yI, bool &ini1On)
{
	if (naveTiroOn == true)
	{
		SDL_Rect tiro = { 0, 0, 3, 12 };
		SDL_Rect tiro1 = { navex, navey, 3, 12 };
		SDL_RenderCopy(r, tex_tiro, &tiro, &tiro1);
	}
	if (naveTiroOn == true)
	{
		navey -= speed + 10;
		if (navey <= 0)
		{
			naveTiroOn = false;
		}
	}
	if ((xI < navex && (navex + 3 < (xI + 40))) || (xI + 40 < navex) && (navex + 3 < (xI + 40)))
	{
		if ((yI < navey && (navey < (yI + 30))) || (yI + 30 < navey) && (navey < (yI + 30)))
		{
			naveTiroOn = false;
			ini1On = false;

		}
	}
}

void Tiros::NaveAtirar2(SDL_Renderer* r, int xII, int yII, bool &ini2On)
{
	if ((xII < navex && (navex + 3 < (xII + 40))) || (xII + 40 < navex) && (navex + 3 < (xII + 40)))
	{
		if ((yII < navey && (navey < (yII + 30))) || (yII + 30 < navey) && (navey < (yII + 30)))
		{
			naveTiroOn = false;
			ini2On = false;
		}
	}
}

void Tiros::NaveAtirar3(SDL_Renderer* r, int xIII, int yIII, bool &ini3On)
{

	if ((xIII < navex && (navex + 3 < (xIII + 40))) || (xIII + 40 < navex) && (navex + 3 < (xIII + 40)))
	{
		if ((yIII < navey && (navey < (yIII + 30))) || (yIII + 30 < navey) && (navey < (yIII + 30)))
		{
			naveTiroOn = false;
			ini3On = false;
		}
	}
}

void Tiros::NaveAtirar4(SDL_Renderer* r, int xIV, int yIV, bool &ini4On)
{

	if ((xIV < navex && (navex + 3 < (xIV + 40))) || (xIV + 40 < navex) && (navex + 3 < (xIV + 40)))
	{
		if ((yIV < navey && (navey < (yIV + 30))) || (yIV + 30 < navey) && (navey < (yIV + 30)))
		{
			naveTiroOn = false;
			ini4On = false;
		}
	}
}

void Tiros::ProcessInput(SDL_Event e, int naveX, int naveY)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_UP)
		{
			naveTiroOn = true;
			navex = naveX + 19;
			navey = naveY;
		}
	}
}

void Tiros::InimigoAtirar1(SDL_Renderer* r, int inimX, int inimY, bool & inimigo1On)
{
	if (inimigo1On == true)
	{
		if (contador % 120 == 0)
		{
			inimTiroOn1 = true;
			inimx = inimX + 19;
			inimy = inimY + 29;
		}
		if (inimTiroOn1 == true)
		{
			SDL_Rect tiro2 = { 0, 0, 4, 8 };
			SDL_Rect tiro3 = { inimx, inimy, 3, 12 };
			SDL_RenderCopy(r, tex_tiro1, &tiro2, &tiro3);
		}
		if (inimy >= 518)
		{
			inimTiroOn1 = false;
		}
		if (inimTiroOn1 == true)
		{
			inimy += speed + 20;
		}
	}
}

void Tiros::InimigoAtirar2(SDL_Renderer* r, int inimX, int inimY, bool &inimigo2On)
{
	if (inimigo2On == true)
	{
		if (contador % 100 == 0)
		{
			inimTiroOn2 = true;
			inimx = inimX + 19;
			inimy = inimY + 29;
		}
		if (inimTiroOn2 == true)
		{
			SDL_Rect tiro2 = { 0, 0, 4, 8 };
			SDL_Rect tiro3 = { inimx, inimy, 3, 12 };
			SDL_RenderCopy(r, tex_tiro1, &tiro2, &tiro3);
		}
		if (inimy >= 518)
		{
			inimTiroOn2 = false;
		}
		if (inimTiroOn2 == true)
		{
			inimy += speed + 15;
		}
	}
}

void Tiros::InimigoAtirar3(SDL_Renderer* r, int inimX, int inimY, bool &inimigo3On)
{
	if (inimigo3On == true)
	{
		if (contador % 80 == 0)
		{
			inimTiroOn3 = true;
			inimx = inimX + 19;
			inimy = inimY + 29;
		}
		if (inimTiroOn3 == true)
		{
			SDL_Rect tiro2 = { 0, 0, 4, 8 };
			SDL_Rect tiro3 = { inimx, inimy, 3, 12 };
			SDL_RenderCopy(r, tex_tiro1, &tiro2, &tiro3);
		}
		if (inimy >= 518)
		{
			inimTiroOn3 = false;
		}
		if (inimTiroOn3 == true)
		{
			inimy += speed + 15;
		}
	}
}

void Tiros::InimigoAtirar4(SDL_Renderer* r, int inimX, int inimY, bool &inimigo4On)
{
	if (inimigo4On == true)
	{
		if (contador % 60 == 0)
		{
			inimTiroOn4 = true;
			inimx = inimX + 19;
			inimy = inimY + 29;
		}
		if (inimTiroOn4 == true)
		{
			SDL_Rect tiro2 = { 0, 0, 4, 8 };
			SDL_Rect tiro3 = { inimx, inimy, 3, 12 };
			SDL_RenderCopy(r, tex_tiro1, &tiro2, &tiro3);
		}
		if (inimy >= 518)
		{
			inimTiroOn4 = false;
		}
		if (inimTiroOn4 == true)
		{
			inimy += speed + 15;
		}
	}
}

void Tiros::Update()
{
	contador++;
}

void Tiros::Died(int &estado, int naveX, int naveY)
{
	if ((naveX < inimx && (inimx + 3 < (naveX + 40))) || (naveX + 40 < inimx) && (inimx + 3 < (naveX + 40)))
	{
		if ((naveY < inimy && (inimy + 12 < (naveY + 30))) || (naveY + 30 < inimy) && (inimy + 12 < (naveY + 30)))
		{
			estado = 2;
		}
	}
	if ((naveX < inimx && (inimx + 3 < (naveX + 40))) || (naveX + 40 < inimx) && (inimx + 3 < (naveX + 40)))
	{
		if ((naveY < inimy && (inimy + 12< (naveY + 30))) || (naveY + 30 < inimy) && (inimy + 12 < (naveY + 30)))
		{
			estado = 2;
		}
	}
	if ((naveX < inimx && (inimx + 3 < (naveX + 40))) || (naveX + 40 < inimx) && (inimx + 3 < (naveX + 40)))
	{
		if ((naveY < inimy && (inimy + 12 < (naveY + 30))) || (naveY + 30 < inimy) && (inimy + 12 < (naveY + 30)))
		{
			estado = 2;
		}
	}
	if ((naveX < inimx && (inimx + 3 < (naveX + 40))) || (naveX + 40 < inimx) && (inimx + 3 < (naveX + 40)))
	{
		if ((naveY < inimy && (inimy + 12 < (naveY + 30))) || (naveY + 30 < inimy) && (inimy + 12 < (naveY + 30)))
		{
			estado = 2;
		}
	}
}