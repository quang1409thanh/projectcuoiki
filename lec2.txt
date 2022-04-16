/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// start up SDL and create window
bool init();

//load media
bool loadMedia();

// Free media and shuts downs SDL
void close();

// the windowns we'll be rendering to-của sổ mà chúng tôi sẽ hiện thị cho
SDL_Window* gWindow=NULL;

// the surface contained by the windows-bề mặt được chứa bởi các cửa sổ
SDL_Surface* gScreenSurface=NULL;

// the image we will load and show on the screen-hình ảnh mà chúng tôi sẽ tải và hiển thị trên màn hình
SDL_Surface* gHelloWorld=NULL;

bool init(){
    //Initialization flag-biến đánh dấu khởi tạo
    bool success = true;
    //Initialization SDL-khởi tạo SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success=false;
	}
	else
	{
		//Create window-tạo cửa sổ
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success=false;
		}
		else
		{
			//Get window surface-lấy bề mặt của cửa sổ
			gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}

bool loadMedia(){
    // Loading success flag -biến đánh dấu tải thành công
    bool success = true;
    // load splash image-tải hình ảnh splash
    gHelloWorld = SDL_LoadBMP("dot.bmp");
    if( gHelloWorld == NULL){
        printf("Unable to load image %s! SDL Error: %s\n", "dot.bmp", SDL_GetError());
        success = false ;
    }
    return success ;
}

void close(){
    //Deallocate surface - hủy bề mặt
    SDL_FreeSurface( gHelloWorld);
    gHelloWorld = NULL;
    //Destroy window - hủy cửa sổ
    SDL_DestroyWindow( gWindow);
    gWindow = NULL;
    // Quit SDL subsystems - thoát các hệ thống phục vụ SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
    if(!init()){
        printf("Failed to initialize!\n");
    }
    else {
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else {
            //Apply the image -áp dụng hình ảnh
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL);
            //Update the surface - cập nhật bề mặt
            SDL_UpdateWindowSurface( gWindow);
            //Wait two seconds - chờ 2 giây
            SDL_Delay( 2000 );
        }
    }
    // Free resources and close SDL-hủy các tài nguyên và đóng SDL
    close();
    return 0;
}