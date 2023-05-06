#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "var_screen.h"
#include <iostream>
//====== khởi tạo class cho đối tượng mái chèo
class Paddle
{

private:
	int mPosXP, mPosYP;

	int mVelXP, mVelYP;

	SDL_Rect mPaddle;

public:
	static const int PADDLE_WIDTH = 90;
	static const int PADDLE_HEIGHT = 20;

	static const int PADDLE_VEL = 10;

	// Initializes the variables
	Paddle();

	void handleEventPaddle(SDL_Event &e);

	void moveP();

	void renderP(LTexture &gPaddleTexture, SDL_Renderer *&gRenderer);

	// void set_TexturePaddle(LTexture gPaddle, std::string path, SDL_Renderer* gRenderer);

	void set_Pos(int x, int y);
	int getPosXP();
	int getPosYP();
	int getVelXP();
	int getVelYP();
	int setPosXP(int &x);
	int setPosYP(int &y);

	LTexture getTextureP();
	SDL_Rect getColliderP();

	void freeP(LTexture &gPaddleTexture);
};
