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
	gPaddleTexture.loadFromFile("source1/img/paddle/paddlelarge.png");
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
	gGameOverTexture.loadFromFile("gameover.png");
	gBgTexture.loadFromFile("bgr.jpg");
	gGameWin.loadFromFile("win.png");
    ballcollision=Mix_LoadWAV("source1/audio/sfx/ballcollision.wav");
    brickcollision=Mix_LoadWAV("source1/audio/sfx/brickcollision.wav");
	gFont= TTF_OpenFont( "font (2).ttf", 28 );
	for(int i=0;i<5;i++){
	dot.set_gDot_Texture("source1/img/anim/ballanim.png",i);
	}
	for(int i=0;i<4;i++){
	gButtonAbout.set_texture("source1/img/buttons/aboutbutton.png",i);
	}
	gButtonAbout.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 2*SCREEN_HEIGHT/4 - 2*BUTTON_HEIGHT/4);
	for(int i=0;i<4;i++){
	gButtonPlay.set_texture("source1/img/buttons/playbutton.png",i);
	}
	gButtonPlay.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT/4  - BUTTON_HEIGHT/4);
		for(int i=0;i<4;i++){
	gButtonExit.set_texture("source1/img/buttons/exitbutton.png",i);
	}
	gButtonExit.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 4*SCREEN_HEIGHT/4 -40 - 4*BUTTON_HEIGHT/4 );
		for(int i=0;i<4;i++){
	gButtonSound.set_texture("source1/img/buttons/soundbutton.png",i);
	}
	gButtonSound.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 3*SCREEN_HEIGHT/4  - 3*BUTTON_HEIGHT/4);
	for(int i=0;i<4;i++){
	gButton1_Pause.set_texture("source1/img/buttons/pausebutton.png",i);
	}
	gButton1_Pause.setPosition(SCREEN_WIDTH-85, SCREEN_HEIGHT-70);
	for(int i=0;i<4;i++){
	gButton1_Reset.set_texture("source1/img/buttons/resetbutton.png",i);
	}
	gButton1_Reset.setPosition(SCREEN_WIDTH-43, SCREEN_HEIGHT-70);
	for(int i=0;i<4;i++){
	gButton1_Back.set_texture("source1/img/buttons/backbutton.png",i);
	}
	gButton1_Back.setPosition(80, 100);
	for(int i=0;i<4;i++){
	gButtonRestart.set_texture("source1/img/buttons/restartbutton.png",i);
	}
	gButtonRestart.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 2*SCREEN_HEIGHT/4+40 - 2*BUTTON_HEIGHT/4);
		for(int i=0;i<4;i++){
	gButtonMainmenu.set_texture("source1/img/buttons/mainmenubutton.png",i);
	}
	gButtonMainmenu.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 3*SCREEN_HEIGHT/4 - 3*BUTTON_HEIGHT/4);
	
}

void close()
{

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;
	gDotTexture.free();
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
	//Rendered texture
	gTextTexture.free();

	//Scene textures
	gFPSTextTexture.free();
	gGameOverTexture.free();
	gGameWin.free();
	ghigh_Score.free();
	gBgTexture.free();
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
}
