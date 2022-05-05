/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL,SDL_image, standard math, and strings
#include <SDL.h>

#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 1,
    //BUTTON_SPRITE_MOUSE_UP = 3,
    //BUTTON_SPRITE_TOTAL = 4
};

//Texture wrapper class
class LTexture 
{
	public:
	//Initializes variables - khởi tạo biến
	LTexture();

	//Deallocates memory - giải phóng bộ nhớ
	~LTexture();

	//load image at specified path - tải hình ảnh tại đường dẫn đã chỉ định
	bool loadFromFile( std::string path);

	#if defined(SDL_TTF_MAJOR_VERSION)
	//Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
	#endif

	//Deallocates texture - giải phóng kết cấu
	void free();

	//Set color modulation - đặt màu sắc
	void setColor( Uint8 red, Uint8 green, Uint8 blue );

	//Set blending
	void setBlendMode( SDL_BlendMode blending );

	//Set alpha modulation
	void setAlpha( Uint8 alpha );

	//Rendes texture at given point - hiển thị kết cấu tại điểm đã chỉ định
	void render ( int x, int y, SDL_Rect* clip = NULL,  double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	//get image dimensions- lấy kích thước hình ảnh
	int getWidth();
	int getHeight();
	private:
	// the actual hardware texture - kết cấu
	SDL_Texture *mTexture;

	// image dimensions - kích thước
	int mWidth;
	int mHeight;

};

//The mouse button
class LButton
{
    public:
        //Initializes internal variables
        LButton();

        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        void handleEvent( SDL_Event* e );
    
        //Shows button sprite
        void render();

    private:
        //Top left position
        SDL_Point mPosition;

        //Currently used global sprite
        LButtonSprite mCurrentSprite;
};
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to-Cửa sổ chứa các kết cấu
SDL_Window* gWindow = NULL;
	
//The window renderer-cửa sổ kết xuất
SDL_Renderer* gRenderer = NULL;


//Mouse button sprites
SDL_Rect gSpriteClips[ 2 ];
LTexture gButton_About_Texture;

//Buttons objects
LButton gButton_About ; 

LTexture::LTexture()
{
	//Initialize-khởi tạo
	mTexture = NULL;
	mWidth=0;
	mHeight=0;
}

LTexture::~LTexture()
{
	//Deallocate-giải phóng
	free();
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
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
bool LTexture::loadFromRenderedText(std::string textureText,SDL_Color textColor)
{
	//Get rid of preexisting texture-Loại bỏ kết cấu có sẵn
	free();

	//Render text surface-Tạo kết cấu từ chuỗi văn bản
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL)
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels-Tạo kết cấu từ màu sắc của khuôn mẫu
		mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions-Lấy kích thước hình ảnh
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface-Giải phóng khuôn mẫu cũ
		SDL_FreeSurface( textSurface );
	}
	//return success-trả về thành công
	return mTexture != NULL;

}
#endif

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent( SDL_Event* e )
{
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
		//Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < mPosition.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT )
        {
            inside = false;
        }
		//Mouse is outside button
        if( !inside )
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;
            
                case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;
                
                // case SDL_MOUSEBUTTONUP:
                // mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                // break;
            }
        }
    }
}

void LButton::render()
{
    //Show current button sprite
    gButton_About_Texture.render( mPosition.x, mPosition.y, &gSpriteClips[ mCurrentSprite ] );
}

void LTexture::free()
{
	//Free texture if it exists-giải phóng kết cấu nếu nó tồn tại
	if(mTexture!=NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture=NULL;
		mWidth=0;
		mHeight=0;
	}
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

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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
			}
		}
	}

	return success;
}

// bool loadMedia()
// {
// 	//Loading success flag
// 	bool success = true;

// 	//Load sprites
// 	if( !gButton_About_Texture.loadFromFile( "media/medialec17/button.png" ) )
// 	{
// 		printf( "Failed to load button sprite texture!\n" );
// 		success = false;
// 	}
// 	else
// 	{
// 		//Set sprites
// 		for( int i = 0; i < BUTTON_SPRITE_TOTAL; ++i )
// 		{
// 			gSpriteClips[ i ].x = 0;
// 			gSpriteClips[ i ].y = i * 200;
// 			gSpriteClips[ i ].w = BUTTON_WIDTH;
// 			gSpriteClips[ i ].h = BUTTON_HEIGHT;
// 		}

// 		//Set buttons in corners
// 		gButtons[ 0 ].setPosition( 0, 0 );
// 		gButtons[ 1 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, 0 );
// 		gButtons[ 2 ].setPosition( 0, SCREEN_HEIGHT - BUTTON_HEIGHT );
// 		gButtons[ 3 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT );
// 	}

// 	return success;
// }

void close()
{
	//Free loaded images
	gButton_About_Texture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Angle of rotation
            double degrees = 0;

			//Flip type
            SDL_RendererFlip flipType = SDL_FLIP_NONE;

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
				
				// Handle button events-Xử lý sự kiện nút
                gButton_About.handleEvent( &e );
                }

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render buttons
                gButton_About.render();
				//Update screen-cập nhật màn hình
				SDL_RenderPresent( gRenderer );
				
			}
	//Free resources and close SDL-
	close();

	return 0;
}