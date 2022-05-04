/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include<iostream>
#include"var_common.h"

#include"LTexture.h"
#include"var_texture.h"
#include"LTimer.h"
//#include"LButton.h"
////Mouse button sprites
//SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
//LTexture gButtonAbout;
//LTexture gButtonPlay;
//LTexture gButtonExit;
//LTexture gButtonSound;
//
////Buttons objects
//LButton gButtons[TOTAL_BUTTONS];
#include"fun_common.h"
#include"Paddle.h"
Paddle paddle;
#include"Brick.h"
#include"Dot.h"
Dot dot;
#include"play.h"
int main(int argc, char* args[])
{
	init();

	loadMedia();
	play();
	//else {
	//	close();
	//	lose();
	//}
	//close();
	////Quit SDL subsystems
	//TTF_Quit();
	//IMG_Quit();
	//SDL_Quit();
	std::cout << COUNT_DIES << std::endl;
	return 0;
}