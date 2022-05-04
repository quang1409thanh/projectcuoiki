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
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 650;

const int BRICK_ROWS = 7;
const int BRICK_COLUMNS = 5;
int COUNT_DIES=2;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
Mix_Chunk *ballcollision=NULL;
Mix_Chunk *brickcollision=NULL;
//Globally used font
TTF_Font *gFont = NULL;

int count_Broken_Bricks=0;




//Texture wrapper class

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		//Creates image from font string
    	//bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		
		#if defined(SDL_TTF_MAJOR_VERSION)
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};



LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	//Return success
	return mTexture != NULL;
}
#endif

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
//Scene textures
LTexture gDotTexture;
LTexture gPaddleTexture;
LTexture gBrickTexture;
//Rendered texture
LTexture gTextTexture;

//Scene textures
LTexture gFPSTextTexture;
LTexture gGameOverTexture;

//The application time based timer
class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};


LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void LTimer::stop()
{
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void LTimer::pause()
{
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused )
    {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

void LTimer::unpause()
{
    //If the timer is running and paused
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
    }
}

Uint32 LTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool LTimer::isStarted()
{
	//Timer is running and paused or unpaused
    return mStarted;
}

bool LTimer::isPaused()
{
	//Timer is running and paused
    return mPaused && mStarted;
}


void init()
{
	//Initialization flag
	//bool success = true;

	//Initialize SDL
	// if( SDL_Init( SDL_INIT_VIDEO  | SDL_INIT_AUDIO) < 0 )
	// {
	// 	printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	// 	success = false;
	// }
	// else
	// {
	// 	//Set texture filtering to linear
	// 	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	// 	{
	// 		printf( "Warning: Linear texture filtering not enabled!" );
	// 	}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		// if( gWindow == NULL )
		// {
		// 	printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		// 	success = false;
		// }
		// else
		// {
		// 	//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			// if( gRenderer == NULL )
			// {
			// 	printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			// 	success = false;
			// }
			// else
			// {
			// 	//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				IMG_Init( imgFlags );
				// if( !( IMG_Init( imgFlags ) & imgFlags ) )
				// {
				// 	printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				// 	success = false;
				// }
                //  //Initialize SDL_mixer
				Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
				// if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				// {
				// 	printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				// 	success = false;
				// }
				 //Initialize SDL_ttf
				 TTF_Init();
                // if( TTF_Init() == -1 )
                // {
                //     printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                //     success = false;
                // }
	// 		}
	// 	}
	// }

	// return success;
}

void loadMedia()    
{
	//Loading success flag
	//bool success = true;

	//Load press texture
	gDotTexture.loadFromFile( "media/medialec27/dot.bmp" );
	gPaddleTexture.loadFromFile("source1/img/paddle/paddlelarge.png");
	gBrickTexture.loadFromFile("source1/img/bricks/blue.png");
	gGameOverTexture.loadFromFile("gameover.png");
	// if( !gDotTexture.loadFromFile( "media/medialec27/dot.bmp" )||!gPaddleTexture.loadFromFile("source1/img/paddle/paddlelarge.png")||!gBrickTexture.loadFromFile("source1/img/bricks/blue.png")||!gGameOverTexture.loadFromFile("gameover.png"))
	// {
	// 	printf( "Failed to load dot texture!\n" );
	// 	success = false;
	// }
    ballcollision=Mix_LoadWAV("source1/audio/sfx/ballcollision.wav");
    // if(ballcollision==NULL)
    // {
    //     printf("Failed to load ballcolision sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
    brickcollision=Mix_LoadWAV("source1/audio/sfx/brickcollision.wav");
    // if(brickcollision==NULL)
    // {
    //     printf("Failed to load brickcolision sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
	gFont= TTF_OpenFont( "media/medialec16/lazy.ttf", 28 );
	// if( gFont == NULL ){
	// 	printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
	// 	success = false;
	// }
	// else
	// {
	// 	//Render text-Tạo kết cấu từ chuỗi văn bản
		SDL_Color textColor = { 0, 0, 0 };
		gTextTexture.loadFromRenderedText( "game brick", textColor );
		// if( !gTextTexture.loadFromRenderedText( "game brick", textColor ) )
		// {
		// 	printf( "Failed to render text texture!\n" );
		// 	success = false;
		// }
	// }
    // return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	gPaddleTexture.free();
	gBrickTexture.free();
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
class Paddle
{
    public:
		//The dimensions of the dot
		static const int PADDLE_WIDTH = 128;
		static const int PADDLE_HEIGHT = 21;

		//Maximum axis velocity of the dot
		static const int PADDLE_VEL = 10;

		//Initializes the variables
		Paddle();

		//Takes key presses and adjusts the dot's velocity
		void handleEventPaddle( SDL_Event& e );

		//Moves the dot and checks collision
		void moveP();

		//Shows the dot on the screen
		void renderP();

		int getPosXP();
		int getPosYP();
		int getVelXP();
		int getVelYP();
    private:
		//The X and Y offsets of the dot
		int mPosXP, mPosYP;

		//The velocity of the dot
		int mVelXP, mVelYP;
		
		//Dot's collision box
		SDL_Rect mPaddle;
};


int Paddle::getPosXP(){
	return mPosXP;
}
int Paddle::getPosYP(){
	return mPosYP;
}
int Paddle::getVelXP(){
	return mVelXP;
}
int Paddle::getVelYP(){
	return mVelYP;
}

Paddle::Paddle(){
	mPosXP = SCREEN_WIDTH/2 - PADDLE_WIDTH/2;
	mPosYP = (SCREEN_HEIGHT-100) - PADDLE_HEIGHT;
	mVelXP = 0;
	mVelYP = 0;
	mPaddle.w = PADDLE_WIDTH;
	mPaddle.h = PADDLE_HEIGHT;
}

void Paddle::handleEventPaddle( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelYP -= PADDLE_VEL; break;
            // case SDLK_DOWN: mVelYP += PADDLE_VEL; break;
            case SDLK_LEFT: mVelXP -= PADDLE_VEL; break;
            case SDLK_RIGHT: mVelXP += PADDLE_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelYP += PADDLE_VEL; break;
            // case SDLK_DOWN: mVelYP -= PADDLE_VEL; break;
            case SDLK_LEFT: mVelXP += PADDLE_VEL; break;
            case SDLK_RIGHT: mVelXP -= PADDLE_VEL; break;
        }
    }
}
void Paddle::moveP(){
    //Move the dot left or right
    mPosXP += mVelXP;
	mPaddle.x = mPosXP;

    //If the dot collided or went too far to the left or right
			if( ( mPosXP < 0 ) || ( mPosXP + PADDLE_WIDTH > SCREEN_WIDTH )  )
				{
					//Move back
					mPosXP -= mVelXP;
					mPaddle.x = mPosXP;
					}

    //Move the dot up or down
    mPosYP += mVelYP;
	mPaddle.y = mPosYP;

    //If the dot collided or went too far up or down
	
			 if( ( mPosYP < 0 ) || ( mPosYP + PADDLE_HEIGHT > (SCREEN_HEIGHT-100) ) )
				{
					//Move back
					mPosYP -= mVelYP;
					mPaddle.y = mPosYP;
					}
}
//Starts up SDL and creates window
void Paddle::renderP(){
	//Render paddle
	gPaddleTexture.render(mPosXP, mPosYP);
}

Paddle paddle;

class Brick{
	public:
		//The dimensions of the dot
		static const int BRICK_WIDTH = 80;
		static const int BRICK_HEIGHT = 35;

		//Maximum axis velocity of the dot
		static const int BRICK_VEL = 0;

		//Initializes the variables
		Brick();

		//Takes key presses and adjusts the dot's velocity
		void handleEventBrick( SDL_Event& e );

		//Moves the dot and checks collision
		void moveB( Brick **brick );

		//Shows the dot on the screen
		void renderB();

		int getPosXB();
		int getPosYB();
		int getVelXB();
		int getVelYB();

		Brick setBrick_mPosXB(int x);

		Brick setBrick(int x, int y, int velx, int vely, int w, int h);

		LTexture gBricks;
	private:
		//The X and Y offsets of the dot
		int mPosXB, mPosYB;

		//The velocity of the dot
		int mVelXB, mVelYB;
		
		//Dot's collision box
		SDL_Rect mBrick;
		
		//int mR, mG, mB, mA, mS, mT;
};
Brick::Brick(){
	mPosXB=100;
	mPosYB=100;
	mVelXB=0;
	mVelYB=0;
	mBrick={mPosXB,mPosYB,BRICK_WIDTH,BRICK_HEIGHT};
}

int Brick::getPosXB(){
	return mPosXB;
}
int Brick::getPosYB(){
	return mPosYB;
}
int Brick::getVelXB(){
	return mVelXB;
}
int Brick::getVelYB(){
	return mVelYB;
}


Brick Brick::setBrick(int x, int y, int velx, int vely, int w, int h){
	mPosXB=x;
	mPosYB=y;
	mVelXB=velx;
	mVelYB=vely;
	mBrick={x,y,w,h};
    return *this;
}
Brick Brick::setBrick_mPosXB(int x){
    mPosXB=x;
    return *this;
}

void Brick::renderB(){
	//Render the dot
	gBrickTexture.render(mPosXB, mPosYB);
}
//Box collision detector
bool checkCollision( SDL_Rect a, Brick b );
//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and checks collision
		void move( Brick brick[BRICK_ROWS][BRICK_COLUMNS] );

		//Shows the dot on the screen
		void render();
        void ball_brick_collision(Brick brick[BRICK_ROWS][BRICK_COLUMNS]);

        int set_mVelY(int& y);
		void restart();
    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		
		//Dot's collision box
		SDL_Rect mCollider;
};

Dot::Dot()
{
    //Initialize the offsets
    mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
    mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;

	//Set collision box dimension
	mCollider.w = DOT_WIDTH;
	mCollider.h = DOT_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelY -= DOT_VEL; break;
            // case SDLK_DOWN: mVelY += DOT_VEL; break;
            // case SDLK_LEFT: {
			// 	mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
   			// 	mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;
 			// 	break;
			// 	 }
            // case SDLK_RIGHT: {
			// 	mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
   			// 	mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;
 			// 	break;
			// 	 }
			case SDLK_1: {
				mVelX=-10;
				mVelY=-10;
			}
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelY += DOT_VEL; break;
            // case SDLK_DOWN: mVelY -= DOT_VEL; break;
            // case SDLK_LEFT: {
			// 	mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
   			// 	mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;
 			// 	break;
			// 	 }
            // case SDLK_RIGHT: {
			// 	mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
   			// 	mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;
 			// 	break;
			// 	 }
			case SDLK_1: {
				mVelX=-10;
				mVelY=-10;
			}
        }
    }
}
void Dot::ball_brick_collision(Brick brick[BRICK_ROWS][BRICK_COLUMNS]){
    bool a;
    for(int i=0;i<BRICK_ROWS;i++){
        for(int j=0;j<BRICK_COLUMNS;j++){
            a=checkCollision(mCollider,brick[i][j]);
            if(a==true){
            brick[i][j]=brick[i][j].setBrick_mPosXB(30000);
            mVelY*=-1;
            //delete_brick_count++;
            }
            a=false;
        }
    }
}

void gameOver();
void Dot::move( Brick brick[BRICK_ROWS][BRICK_COLUMNS] ){
	int PADDLE_HEIGHT=paddle.PADDLE_HEIGHT;
	int PADDLE_WIDTH=paddle.PADDLE_WIDTH;
	int batx=paddle.getPosXP();
	int baty=paddle.getPosYP();
    //Move the dot left or right
    mPosX += mVelX;
	mCollider.x = mPosX;
	
    //If the dot collided or went too far to the left or right
	for(int i=0;i<BRICK_ROWS;i++){
		for(int j=0;j<BRICK_COLUMNS;j++){
			if(checkCollision( mCollider, brick[i][j] ) )
				{
					//Move back
					Mix_PlayChannel(-1,brickcollision,0);
					mVelX*=-1;
					mVelY*=-1;
                    
				}
		}
	}
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) ) {
        mVelX *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }
	mPosY += mVelY;
	mCollider.y = mPosY;
    //Move the dot up or down
    // chỗ này di chuyển đúng nhưng âm thanh ko đúng

    //If the dot collided or went too far up or down
	for(int i=0;i<BRICK_ROWS;i++){
		for(int j=0;j<BRICK_COLUMNS;j++){
			 if( checkCollision( mCollider, brick[i][j] ) )
				{
					//Move back
					//count_Broken_Bricks++;
					Mix_PlayChannel(-1,brickcollision,0);
					count_Broken_Bricks++;
                    
				}
		}
	}
    if( mPosY < 0 ) {
        mVelY *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }
	if(mPosY + DOT_HEIGHT > (SCREEN_HEIGHT-100) ){
		mPosX=batx+PADDLE_WIDTH/2-DOT_WIDTH/2;
		mPosY=SCREEN_HEIGHT-100-DOT_HEIGHT-paddle.PADDLE_HEIGHT;
		mVelX=10;
		mVelY=10;
		COUNT_DIES--;
	}
	// if(COUNT_DIES<0) {
	// 	gameOver();
	// }
	int ballscaling=PADDLE_HEIGHT;// hoặc bằng 20 check sau đoạn này 
    if(mPosY+ballscaling>=baty&&mPosY<=(SCREEN_HEIGHT-100)&&mPosX>=batx&&mPosX<=batx+PADDLE_WIDTH){
        mVelY*=-1;
		//Mix_PlayChannel(-1,ballcollision,0);
    }
	// if(mPosY+ballscaling>baty&&mPosY<SCREEN_HEIGHT&&mPosX>batx&&mPosX<batx+PADDLE_WIDTH){
	// 	mVelX*=-1;
	// 	Mix_PlayChannel(-1,ballcollision,0);
	// }
	// ** lưu ý chỗ lỗi thì ko phải là trường hợp gameover hôm sau cần fix cho chuẩn xác
}
void Dot::render()
{
    //Show the dot
	
	gDotTexture.render( mPosX, mPosY );
}

			
Dot dot;


void gameOver(){
	gDotTexture.free();
	gPaddleTexture.free();
	gBrickTexture.free();
    //Free loaded images
    gTextTexture.free();
	//Free loaded images
	gFPSTextTexture.free();
    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;
		SDL_DestroyRenderer( gRenderer );
	SDL_SetRenderDrawColor( gRenderer, 0xF0, 0xFF, 0xFF, 0xFF );
	gGameOverTexture.render( SCREEN_WIDTH/2-gGameOverTexture.getWidth()/2, SCREEN_HEIGHT/2-gGameOverTexture.getHeight()/2 );
	SDL_RenderPresent( gRenderer );
	SDL_Delay(2000);
}
bool checkCollision( SDL_Rect a, Brick b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.getPosXB();
    rightB = b.getPosXB() + b.BRICK_WIDTH;
    topB = b.getPosYB();
    bottomB = b.getPosYB()+ b.BRICK_HEIGHT;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	// if( !init() )
	// {
	// 	printf( "Failed to initialize!\n" );
	// }
	init();
	// else
	// {
		//Load media
	loadMedia();
		// if( !loadMedia() )
		// {
		// 	printf( "Failed to load media!\n" );
		// }
		// else
		// {	
			// gameloop
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
            Brick brick[BRICK_ROWS][BRICK_COLUMNS];
            for(int i=0;i<BRICK_ROWS;i++)
            {
                for(int j=0;j<BRICK_COLUMNS;j++)
                {
                    brick[i][j]=brick[i][j].setBrick(20+i*brick[i][j].BRICK_WIDTH,j*brick[i][j].BRICK_HEIGHT,0,0,brick[i][j].BRICK_WIDTH,brick[i][j].BRICK_HEIGHT);
                }
            }
			//Angle of rotation
            double degrees = 0;

			//Flip type
            SDL_RendererFlip flipType = SDL_FLIP_NONE;

			//The dot that will be moving around on the screen
			// Dot dot;
			SDL_Color textColor = { 0, 0, 0, 255 };

			//The frames per second timer
			LTimer fpsTimer;

			//In memory text stream
			std::stringstream timeText;

			//Start counting frames per second
			int countedFrames = 0;
			fpsTimer.start();
			
			
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//Handle input for the dot
					dot.handleEvent( e );
					 paddle.handleEventPaddle( e );
					 
				}
                
				//Move the dot and check collision
				dot.move( brick );
                dot.ball_brick_collision(brick);
				paddle.moveP();
				//Calculate and correct fps
				float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
				if( avgFPS > 2000000 )
				{
					avgFPS = 0;
				}
				
				// //Set text to be rendered
				timeText.str( "" );
				timeText << "SCORE:: " << count_Broken_Bricks<<" Live:: "<<COUNT_DIES;
				//Render text
				if( !gFPSTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) )
				{
					printf( "Unable to render FPS texture!\n" );
				}
				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0x0F, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

                //Render dot
				dot.render();
				paddle.renderP();
                for(int i=0;i<BRICK_ROWS;i++)
                {
                    for(int j=0;j<BRICK_COLUMNS;j++)
                    {
                        brick[i][j].renderB();
                    }
                }
				//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
				SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT-100 , SCREEN_WIDTH, SCREEN_HEIGHT -100 );
			    //Render current frame
				gTextTexture.render( 0,SCREEN_HEIGHT -70 );
				gFPSTextTexture.render(  0,SCREEN_HEIGHT -30  );
				//gGameOverTexture.render(10,100);
				//Update screen
				SDL_RenderPresent( gRenderer );
				++countedFrames;
			
    
	}
	//Free resources and close SDL
	close();
	return 0;
}