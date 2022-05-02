
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO  | SDL_INIT_AUDIO) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
                 //Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
				 //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool loadMedia()    
{
	//Loading success flag
	bool success = true;

	//Load press texture
	if( !gDotTexture.loadFromFile( "media/medialec27/dot.bmp" )||!gPaddleTexture.loadFromFile("source1/img/paddle/paddlelarge.png")||!gBrickTexture.loadFromFile("source1/img/bricks/blue.png")||!gameOver.loadFromFile("gameover.png"))
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
    ballcollision=Mix_LoadWAV("source1/audio/sfx/ballcollision.wav");
    if(ballcollision==NULL)
    {
        printf("Failed to load ballcolision sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    brickcollision=Mix_LoadWAV("source1/audio/sfx/brickcollision.wav");
    if(brickcollision==NULL)
    {
        printf("Failed to load brickcolision sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
	gFont= TTF_OpenFont( "media/medialec16/lazy.ttf", 28 );
	if( gFont == NULL ){
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text-Tạo kết cấu từ chuỗi văn bản
		SDL_Color textColor = { 0, 0, 0 };
		if( !gTextTexture.loadFromRenderedText( "game brick", textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}
    return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
    //Free loaded images
    gTextTexture.free();
	//Free loaded images
	gFPSTextTexture.free();
    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
