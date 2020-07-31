#pragma once
#include "Inimigo.h"

Inimigo::Inimigo()
{

}

Inimigo::~Inimigo()
{

}



void Inimigo::Draw(SDL_Renderer* r)
{
	if (inimigo1On == true)
	{
		SDL_Rect ini = { 0, 0, 38, 19 };
		SDL_Rect ini1 = { xI, yI, 40, 30 };
		SDL_RenderCopy(r, tex_Inimigo2, &ini, &ini1);
	}
	if (inimigo2On == true)
	{
		SDL_Rect ini = { 0, 0, 38, 19 };
		SDL_Rect ini1 = { xII, yII, 40, 30 };
		SDL_RenderCopy(r, tex_Inimigo2, &ini, &ini1);
	}
	if (inimigo3On == true)
	{
		SDL_Rect ini = { 0, 0, 38, 19 };
		SDL_Rect ini1 = { xIII, yIII, 40, 30 };
		SDL_RenderCopy(r, tex_Inimigo2, &ini, &ini1);
	}
	if (inimigo4On == true)
	{
		SDL_Rect ini = { 0, 0, 38, 19 };
		SDL_Rect ini1 = { xIV, yIV, 40, 30 };
		SDL_RenderCopy(r, tex_Inimigo2, &ini, &ini1);
	}
	/*if (inimigo5On == true)
	{
		SDL_Rect ini = { 0, 0, 38, 19 };
		SDL_Rect ini1 = { xV, yV, 40, 30 };
		SDL_RenderCopy(r, tex_Inimigo2, &ini, &ini1);
	}*/
}

void Inimigo::MovimentaçãoE()
{
	//Inimigo 1
	if (xI >= 820)
	{
		fimTela1 = true;
	}
	if (fimTela1 == true)
	{
		inicioTela1 = false;
		xI -= speed;
	}
	//Inimigo 2
	if (xII >= 820)
	{
		fimTela2 = true;
	}
	if (fimTela2 == true)
	{
		inicioTela2 = false;
		xII -= speed + 5;
	}
	//Inimigo 3
	if (xIII >= 820)
	{
		fimTela3 = true;
	}
	if (fimTela3 == true)
	{
		inicioTela3 = false;
		xIII -= speed + 8;
	}
	//Inimigo 4
	if (xIV >= 820)
	{
		fimTela4 = true;
	}
	if (fimTela4 == true)
	{
		inicioTela4 = false;
		xIV -= speed + 10;
	}
}

void Inimigo::MovimentaçãoD()
{
	//Inimigo 1
	if (xI <= 0)
	{
		inicioTela1 = true;
	}
	if (inicioTela1 == true)
	{
		fimTela1 = false;
		xI += speed;
	}
	//Inimigo 2
	if (xII <= 0)
	{
		inicioTela2 = true;
	}
	if (inicioTela2 == true)
	{
		fimTela2 = false;
		xII += speed + 5;
	}
	//Inimigo 3
	if (xIII <= 0)
	{
		inicioTela3 = true;
	}
	if (inicioTela3 == true)
	{
		fimTela3 = false;
		xIII += speed + 8;
	}
	//Inimigo 4
	if (xIV <= 0)
	{
		inicioTela4 = true;
	}
	if (inicioTela4 == true)
	{
		fimTela4 = false;
		xIV += speed + 10;
	}
}

void Inimigo::Win(int &estado)
{
	if (inimigo1On == false && inimigo2On == false && inimigo3On == false && inimigo4On == false)
	{
		estado = 3;
	}
}