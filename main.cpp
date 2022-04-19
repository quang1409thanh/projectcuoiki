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

	//Load texture
	gTexture = loadTexture( "medialec9/viewport.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

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
				SDL_SetRenderDrawColor( gRenderer, 0x0F, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				
				// //top left
				// SDL_Rect topleftViewport;
				// topleftViewport.x = 0;
				// topleftViewport.y = 0;
				// topleftViewport.w = SCREEN_WIDTH / 2;
				// topleftViewport.h = SCREEN_HEIGHT / 2;
				// SDL_RenderSetViewport( gRenderer, &topleftViewport );
				// //Render texture to scree- kết xuất texture lên màn hình
				// SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				// //top right
				// SDL_Rect toprightViewport;
				// toprightViewport.x = SCREEN_WIDTH / 2;
				// toprightViewport.y = 0;
				// toprightViewport.w = SCREEN_WIDTH / 2;
				// toprightViewport.h = SCREEN_HEIGHT / 2;
				// SDL_RenderSetViewport( gRenderer, &toprightViewport );
				// //Render texture to screen - kết xuất texture lên màn hình
				// SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				// //bottom 
				// SDL_Rect bottomViewport;
				// bottomViewport.x = 0;
				// bottomViewport.y = SCREEN_HEIGHT / 2;
				// bottomViewport.w = SCREEN_WIDTH;
				// bottomViewport.h = SCREEN_HEIGHT / 2;
				// SDL_RenderSetViewport( gRenderer, &bottomViewport );
				// //Render texture to screen -+ kết xuất texture lên màn hình
				// SDL_RenderCopy( gRenderer, g+Texture, NULL, NULL );

				SDL_Rect bottomViewport;
				bottomViewport.x = SCREEN_HEIGHT / 4;
				bottomViewport.y = SCREEN_HEIGHT / 4;
				bottomViewport.w = SCREEN_WIDTH/2;
				bottomViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport( gRenderer, &bottomViewport );
				//Render texture to screen - kết xuất texture lên màn hình
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				//update screen-câp nhật màn hình
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL- hủy các tài nguyên và đóng SDL
	close();

	return 0;
}