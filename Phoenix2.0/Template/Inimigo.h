#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	
	int xI = 0, yI = 40;
	int xII = 0, yII = 80;
	int xIII = 0, yIII = 120;
	int xIV = 0, yIV = 160;
	int speed = 2;
	bool inimigo1On = true, inimigo2On = true, inimigo3On = true, inimigo4On = true;
	bool fimTela1, inicioTela1;
	bool fimTela2, inicioTela2;
	bool fimTela3, inicioTela3;
	bool fimTela4, inicioTela4;

	void Draw(SDL_Renderer* r);
	void MovimentaçãoE();
	void MovimentaçãoD();
	void Win(int &estado);

	SDL_Texture* tex_Inimigo1;
	SDL_Texture* tex_Inimigo2;
	
};

