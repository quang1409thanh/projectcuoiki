void init()
{
		gWindow = SDL_CreateWindow( "Break Brick Game	", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				IMG_Init( imgFlags );
				Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
				TTF_Init();
}

void loadMedia()    
{
	gPaddleTexture.loadFromFile("source1/img/paddle/paddlemedium.png");
	gBricksTextureBlue.loadFromFile("source1/img/bricks/blue.png");
	gBricksTextureRed.loadFromFile("source1/img/bricks/red.png");
	gBricksTextureGreen.loadFromFile("source1/img/bricks/green.png");
	gBricksTexturDearkgreen.loadFromFile("source1/img/bricks/darkgreen.png");
	gBricksTextureIndigo.loadFromFile("source1/img/bricks/indigo.png");
	gBricksTextureOrange.loadFromFile("source1/img/bricks/orange.png");
	gBricksTexturePink.loadFromFile("source1/img/bricks/pink.png");
	gBricksTextureSolid.loadFromFile("source1/img/bricks/solid.png");
	gBricksTextureViolet.loadFromFile("source1/img/bricks/violet.png");
	gBricksTextureYellow.loadFromFile("source1/img/bricks/yellow.png");
	gGameOverTexture.loadFromFile("media/gameover.png");
	gBgTexture.loadFromFile("media/bgr.jpg");
	gGameWin.loadFromFile("media/win.png");
	gBg_Mainmenu[0].loadFromFile("media/bg_main_menu.jpg");
	gBg_Mainmenu[1].loadFromFile("media/bg_main_menu1.png");
	gBg_About.loadFromFile("media/gBg_About.png");
	gBgTexturelv2.loadFromFile("media/bglv2.jpg");
	gBgLv1.loadFromFile("source1/img/bg.png");
	gTextbox.loadFromFile("source1/img/textbox.png");
	music_Menu=Mix_LoadMUS("source1/audio/music/menu_bg.ogg");
	music_Play=Mix_LoadMUS("source1/audio/music/play_bg.ogg");
	music_GameOver=Mix_LoadMUS("source1/audio/music/gameover_bg.ogg");
	music_GameWin=Mix_LoadMUS("source1/audio/music/gamewinning_bg.ogg");
    ballcollision=Mix_LoadWAV("source1/audio/sfx/ballcollision.wav");
    brickcollision=Mix_LoadWAV("source1/audio/sfx/brickcollision.wav");
	gFont= TTF_OpenFont( "source1/font/font_02/Roboto-Medium.ttf", 40 );
	gFont_HighScore=TTF_OpenFont("source1/font/font_01/DoppioOne-Regular.ttf",23);
	for(int i=0;i<5;i++){
	dot.set_gDot_Texture("source1/img/anim/ballanim.png",i);
	}
	for(int i=0;i<4;i++){
	gButton[ABOUT].set_texture("source1/img/buttons/aboutbutton.png",i);
	}
	gButton[ABOUT].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT-70 -2*BUTTON_HEIGHT- 2*BUTTON_HEIGHT/8);
	for(int i=0;i<4;i++){
	gButton[GAME_PLAY].set_texture("source1/img/buttons/playbutton.png",i);
	}
	gButton[GAME_PLAY].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2,SCREEN_HEIGHT-70 -3*BUTTON_HEIGHT- 3*BUTTON_HEIGHT/8);
		for(int i=0;i<4;i++){
	gButton[EXIT].set_texture("source1/img/buttons/exitbutton.png",i);
	}
	gButton[EXIT].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT -70 );
		for(int i=0;i<4;i++){
	gButton[SOUND].set_texture("source1/img/buttons/soundbutton.png",i);
	}
	gButton[SOUND].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT-70 -BUTTON_HEIGHT- BUTTON_HEIGHT/8);
	for(int i=0;i<4;i++){
	gButton1_Pause.set_texture("source1/img/buttons/pausebutton.png",i);
	}
	for(int i=0;i<4;i++){
		gButton[RESUME].set_texture("source1/img/buttons/resumebutton.png",i);
	}
	gButton[RESUME].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2,SCREEN_HEIGHT-70 -3*BUTTON_HEIGHT- 3*BUTTON_HEIGHT/8);
	gButton1_Pause.setPosition(SCREEN_WIDTH-SCREEN_RIGHT-BUTTON_WIDTH1-BUTTON_WIDTH1-2, 544);
	for(int i=0;i<4;i++){
	gButton1_Reset.set_texture("source1/img/buttons/resetbutton.png",i);
	}
	gButton1_Reset.setPosition(SCREEN_WIDTH-SCREEN_RIGHT-BUTTON_WIDTH1-1, 544);
	for(int i=0;i<4;i++){
	gButton1_Back.set_texture("source1/img/buttons/backbutton.png",i);
	}
	gButton1_Back.setPosition(8, 12);
	for(int i=0;i<4;i++){
	gButton[RESTART].set_texture("source1/img/buttons/restartbutton.png",i);
	}
	gButton[RESTART].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2,SCREEN_HEIGHT-70 -BUTTON_HEIGHT- BUTTON_HEIGHT/8);
		for(int i=0;i<4;i++){
	gButton[MAIN_MENU].set_texture("source1/img/buttons/mainmenubutton.png",i);
	}
	gButton[MAIN_MENU].setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT-70 -2*BUTTON_HEIGHT- 2*BUTTON_HEIGHT/8);

	gButtonsfx.set_texture("source1/img/buttons/sfxoffbutton.png",0);
	gButtonsfx.set_texture("source1/img/buttons/sfxoffbutton.png",1);
	gButtonsfx.set_texture("source1/img/buttons/sfxonbutton.png",2);
	gButtonsfx.set_texture("source1/img/buttons/sfxonbutton.png",3);
	gButtonsfx.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT-70 -BUTTON_HEIGHT- BUTTON_HEIGHT/8);
	gButtonmusic.set_texture("source1/img/buttons/musicoffbutton.png",0);
	gButtonmusic.set_texture("source1/img/buttons/musicoffbutton.png",1);
	gButtonmusic.set_texture("source1/img/buttons/musiconbutton.png",2);
	gButtonmusic.set_texture("source1/img/buttons/musiconbutton.png",3);
	gButtonmusic.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT-70 -2*BUTTON_HEIGHT- 2*BUTTON_HEIGHT/8);
}

void close()
{

    //Free global font
	gPaddleTexture.free();
	gBricksTextureBlue.free();
	gBricksTextureRed.free();
	gBricksTextureGreen.free();
	gBricksTexturDearkgreen.free();
	gBricksTextureIndigo.free();
	gBricksTextureOrange.free();
	gBricksTexturePink.free();
	gBricksTextureSolid.free();
	gBricksTextureViolet.free();
	gBricksTextureYellow.free();
	gGameOverTexture.free();
	gBgTexture.free();
	gGameWin.free();
	gBg_Mainmenu[0].free();
	gBg_Mainmenu[1].free();
	gBg_About.free();
	gBgTexturelv2.free();
	gBgLv1.free();
	gTextbox.free();
	
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
}
