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
#include "setup_Sound.h"
#include"LTexture.h"
#include"var_texture.h"
#include"LTimer.h"
#include"LButton.h"
#include"var_button.h"
#include"LButton1.h"
#include"var_Lbutton1.h"

#include"Brick.h"

#include"Paddle.h"

#include"Dot.h"

#include"fun_common.h"
#include"play.h"
#include"TheGame.h"
int main(int argc, char* args[])
{
	init();

	loadMedia();
    playlv1();
   
	close();

    // tại sao ấn vào play lại mất màn hình chứ :?
	return 0;
}
