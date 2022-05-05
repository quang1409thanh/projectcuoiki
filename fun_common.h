void init()
{
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
	gDotTexture.loadFromFile( "media/medialec27/dot.bmp" );
	gPaddleTexture.loadFromFile("source1/img/paddle/paddlelarge.png");
	gBrickTexture.loadFromFile("source1/img/bricks/blue.png");
	gGameOverTexture.loadFromFile("gameover.png");
	gGameWin.loadFromFile("win.png");
    ballcollision=Mix_LoadWAV("source1/audio/sfx/ballcollision.wav");
    brickcollision=Mix_LoadWAV("source1/audio/sfx/brickcollision.wav");
	gFont= TTF_OpenFont( "font (2).ttf", 28 );
	SDL_Color textColor = { 0, 0, 0 };
	gTextTexture.loadFromRenderedText( "level 1 ", textColor );
	for(int i=0;i<4;i++){
	gButtonAbout.set_texture("source1/img/buttons/aboutbutton.png",i);
	}
	gButtonAbout.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 2*SCREEN_HEIGHT/4 - 2*BUTTON_HEIGHT/4);
	for(int i=0;i<4;i++){
	gButtonPlay.set_texture("source1/img/buttons/playbutton.png",i);
	}
	gButtonPlay.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, SCREEN_HEIGHT/4 - BUTTON_HEIGHT/4);
		for(int i=0;i<4;i++){
	gButtonExit.set_texture("source1/img/buttons/exitbutton.png",i);
	}
	gButtonExit.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 4*SCREEN_HEIGHT/4 - 4*BUTTON_HEIGHT/4);
		for(int i=0;i<4;i++){
	gButtonSound.set_texture("source1/img/buttons/soundbutton.png",i);
	}
	gButtonSound.setPosition(SCREEN_WIDTH/2 - BUTTON_WIDTH/2, 3*SCREEN_HEIGHT/4 - 3*BUTTON_HEIGHT/4);
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	gPaddleTexture.free();
	gBrickTexture.free();
    //Free loaded images
    gTextTexture.free();
	// //Free loaded images
	gFPSTextTexture.free();
    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;


}