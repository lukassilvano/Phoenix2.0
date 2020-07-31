#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "Inimigo.h"
#include "Nave.h"
#include "Tiros.h"
#define MENU 0
#define GAMEPLAY 1
#define GAMEOVER 2
#define WIN 3

using namespace std;

class SDLGame
{
public:
	SDLGame();
	~SDLGame();
		
	int CreateGame();
	void Destroy();
	void Run();
	void Replay();
	
	int contador;
	
private:
	SDL_Surface* surface;
	SDL_Texture* textureMenu;
	SDL_Texture* fundo;
	SDL_Texture* tex_vidas;
	SDL_Texture* barra;
	SDL_Texture* barra1;
	SDL_Texture* barra2;
	SDL_Texture* barra3;
	SDL_Texture* barra4;
	SDL_Texture* barra5;
	SDL_Texture* barra6;
	SDL_Texture* youwin;
	SDL_Texture* gameover;

	
	double deltaTime;
	const int windows_width = 860;
	const int windows_height = 600;
	bool quit;
	int estadoJogo;
	void DrawMenu();
	void DesenhaFundo();
	void Update();
	void ProcessInput();
	void Frames();
	void DesenharBarras();
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Renderer *ini;
	SDL_Event e;

	Inimigo inim1;
	
	Nave nave;
	Tiros tiro;
	
};

int SDLGame::CreateGame()
{
	//inicializa a tela do jogo e todas suas imagens apenas uma vez
	win = SDL_CreateWindow("Nome da janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windows_width, windows_height, 0);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	surface = SDL_LoadBMP("../../ASSET/menu.bmp");
	textureMenu = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/nave.png");
	nave.tex_Nave = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/nave1.png");
	nave.tex_Nave1 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/inimigo.png");
	inim1.tex_Inimigo1 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/inimigo1.png");
	inim1.tex_Inimigo2 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/vidas.png");
	tex_vidas = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/barra3.png");
	barra3 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/fundo.jpg");
	fundo = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/tiro.png");
	tiro.tex_tiro = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/tiro1.png");
	tiro.tex_tiro1 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/youwin.png");
	youwin = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/gameover.png");
	gameover = SDL_CreateTextureFromSurface(ren, surface);

	quit = false;
	contador = 0;
	estadoJogo = MENU;
	return 0;
}

void SDLGame::DesenharBarras()
{
	if (estadoJogo == GAMEPLAY)
	{
		SDL_Rect barra1 = { 0, 0, 384, 270 };
		SDL_Rect barra2 = { 0, 530, 860, 70 };
		SDL_RenderCopy(ren, barra3, &barra1, &barra2);
	}

}

void SDLGame::DesenhaFundo()
{
	SDL_Rect fundo1 = { 0, 0, 1366, 768 };
	SDL_RenderCopy(ren, fundo, &fundo1, 0);
}

void SDLGame::Frames()
{
	int fps = 60;
	int fpsMill = 1000 / fps;
	int currentFrameTime;
	double startTime = SDL_GetTicks();
	currentFrameTime = SDL_GetTicks();
	int pastTime = SDL_GetTicks() - currentFrameTime;
	if (fpsMill > pastTime)
		SDL_Delay(fpsMill - pastTime);
	double endTime = SDL_GetTicks();
	deltaTime = (endTime - startTime) / 1000;
}

void SDLGame::Update()
{
	contador++;
	cout << contador << endl;
}

void SDLGame::DrawMenu()
{
	if (estadoJogo == MENU)
	{
		SDL_Rect menu = { 0, 0, 384, 270 };
		SDL_RenderCopy(ren, textureMenu, &menu, 0);
	
	}
}

void SDLGame::ProcessInput()
{
	//Pegando inputs
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)//Se evento de sair (clicou x)
		{
			quit = true;
		}
		if (estadoJogo == MENU)
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_RETURN)
				{
					estadoJogo = GAMEPLAY;
				}
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}
		}
		else 
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					estadoJogo = MENU;
				}
			}
		}
	}
}

void SDLGame::Run()
{
	while (!quit)
	{
		if (estadoJogo == MENU)
			{
				DrawMenu();
				ProcessInput();
				SDL_RenderPresent(ren);
				
			}
		else if (estadoJogo == GAMEPLAY)
			{
				DesenhaFundo();
				Frames();
				Update();
				tiro.Update();
				ProcessInput();
				DesenharBarras();
				tiro.NaveAtirar1(ren, inim1.xI, inim1.yI, inim1.inimigo1On);
				tiro.NaveAtirar2(ren, inim1.xII, inim1.yII, inim1.inimigo2On);
				tiro.NaveAtirar3(ren, inim1.xIII, inim1.yIII, inim1.inimigo3On);
				tiro.NaveAtirar4(ren, inim1.xIV, inim1.yIV, inim1.inimigo4On);
				tiro.ProcessInput(e, nave.x, nave.y);
				tiro.InimigoAtirar1(ren, inim1.xI, inim1.yI, inim1.inimigo1On);
				tiro.InimigoAtirar2(ren, inim1.xII, inim1.yII, inim1.inimigo2On);
				tiro.InimigoAtirar3(ren, inim1.xIII, inim1.yIII, inim1.inimigo3On);
				tiro.InimigoAtirar4(ren, inim1.xIV, inim1.yIV, inim1.inimigo4On);
				inim1.Draw(ren);
				inim1.MovimentaçãoD();
				inim1.MovimentaçãoE();
				nave.Draw(ren);
				nave.Movimentação(e);
				inim1.Win(estadoJogo);
				tiro.Died(estadoJogo, nave.x, nave.y);
				SDL_RenderPresent(ren);
			}
		else if(estadoJogo == GAMEOVER)
		{
			ProcessInput();
			SDL_Rect go = { 0, 0, 728, 110 };
			SDL_Rect go1 = { 250, 200, 400, 60 };
			SDL_RenderCopy(ren, gameover, &go, &go1);
			SDL_RenderPresent(ren);
		}
		else if (estadoJogo == WIN)
		{
			ProcessInput();
			SDL_Rect yw = { 0, 0, 539, 110 };
			SDL_Rect yw1 = { 250, 200, 400, 81.7 };
			SDL_RenderCopy(ren, youwin, &yw, &yw1);
			SDL_RenderPresent(ren);
		}
	}
}

void SDLGame::Destroy()
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
}

SDLGame::SDLGame(){}

SDLGame::~SDLGame()
{
}