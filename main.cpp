/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL,SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture-Tải hình ảnh riêng lẻ làm kết cấu
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to-Cửa sổ chứa các kết cấu
SDL_Window* gWindow = NULL;
	
//The window renderer-cửa sổ kết xuất
SDL_Renderer* gRenderer = NULL;

//Current displayed texture - cửa sổ hiện tại
SDL_Texture* gTexture = NULL;

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
		//Set texture filtering to linear-Chỉnh lỗi làm mờ
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
			//Create renderer for window-Tạo cửa sổ kết xuất
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color-Khởi tạo màu kết xuất
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading-Khởi tạo tải hình ảnh PNG
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

bool loadMedia()
{
	//Loading success flag- flag load thành công
	bool success = true;

	//Nothing to load-không có gì để tải
	return success;
}

void close()
{
	//Free loaded image- free image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	//Destroy window- hủy cửa sổ
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

	//Quit SDL subsystems- đóng các subsystem của SDL
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture- texture cuối cùng
	SDL_Texture* newTexture = NULL;

	//Load image at specified path- load ảnh tại đường dẫn đã xác định
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
		//Create texture from surface pixels- tạo texture từ pixel của surface
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if(newTexture== NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else {
			//Create texture from surface pixels- tạo texture từ pixel của surface	
			newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			if(newTexture== NULL )
			{
				printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			}
			//Get rid of old loaded surface- hủy surface cũ
			SDL_FreeSurface( loadedSurface );
		}
		
	}

	return newTexture;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running- khi ứng dụng đang chạy
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
				}
				//Clear screen- xóa màn hình
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render red filled quad- kết xuất màu đỏ vào quad
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
				SDL_RenderFillRect( gRenderer, &fillRect );

				//Render green outlined quad- kết xuất màu xanh vào quad
				SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
				SDL_RenderDrawRect( gRenderer, &outlineRect );

				//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
				SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SCREEN_HEIGHT / 3 );

				//Draw vertical line of yellow dots- kết xuất màu vàng vào đường thẳng
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
				for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
				{
					SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
				}
				//update screen-câp nhật màn hình
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL- hủy các tài nguyên và đóng SDL
	close();

	return 0;
}