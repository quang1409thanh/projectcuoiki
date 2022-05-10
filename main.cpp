/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include "var_common.h"

#include"LTexture.h"
#include"var_texture.h"
#include"LTimer.h"
#include"LButton.h"
#include"var_button.h"
#include"LButton1.h"
#include"var_Lbutton1.h"

#include"Paddle.h"
Paddle paddle;
#include"Brick.h"
#include"Dot.h"
Dot dot;
#include"fun_common.h"
#include"play.h"
int main(int argc, char* args[])
{
	init();

	loadMedia();
	//gameloop
	bool isRestart=false;
	do {
		if(!isRestart){
			main_menu();
			if(gButtonExit.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
			{
				break;
			}
		}
		playlv1();
		if(gButtonRestart.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			isRestart=true;
		}
		else isRestart=false;

		if(gButtonExit.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			isRestart=false;
		}
		reset();
		gButtonExit.freeStatus();
		gButtonRestart.freeStatus();
		gButtonMainmenu.freeStatus();
		gButtonPlay.freeStatus();
	}
	while (isRestart);
	std::cout << COUNT_DIES << std::endl;
	close();
	return 0;
}