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


class LTexture {
	private:
	// the actual hardware texture - kết cấu
	SDL_Texture *mTexture;

	// image dimensions - kích thước
	int mWidth;
	int mHeight;
	public:
	//Initializes variables - khởi tạo biến
	LTexture();

	//Deallocates memory - giải phóng bộ nhớ
	~LTexture();

	//load image at specified path - tải hình ảnh tại đường dẫn đã chỉ định
	bool loadFromFile( std::string path);

	//Deallocates texture - giải phóng kết cấu
	void free();

	//Rendes texture at given point - hiển thị kết cấu tại điểm đã chỉ định
	void render ( int x, int y);

	//get image dimensions- lấy kích thước hình ảnh
	int getWidth();
	int getHeight();
};

//The window we'll be rendering to-Cửa sổ chứa các kết cấu
SDL_Window* gWindow = NULL;
	
//The window renderer-cửa sổ kết xuất
SDL_Renderer* gRenderer = NULL;

// //Current displayed texture - cửa sổ hiện tại
// SDL_Texture* gTexture = NULL;

//Scene textures - kết cấu
LTexture gFooTexture;
LTexture gBackgroundTexture;

LTexture::LTexture(){
	//Initialize-khởi tạo
	mTexture = NULL;
	mWidth=0;
	mHeight=0;
}

LTexture::~LTexture(){
	//Deallocate-giải phóng
	free();
	
}

bool LTexture::loadFromFile(std::string path){
	//Get rid of preexisting texture-xóa kết cấu cũ
	free();

	// the final texture-kết cấu cuối cùng
	SDL_Texture *newTexture=NULL;
	
	//load image at the specified path-tải hình ảnh tại đường dẫn đã chỉ định
	SDL_Surface* LoadSurface=IMG_Load(path.c_str());
	if(LoadSurface==NULL){
		printf("Unable to load image %s! SDL_image Error: %s\n",path.c_str(),IMG_GetError());
		return false;
	}
	else {
		// color key image-hình ảnh màu đen
		SDL_SetColorKey(LoadSurface,SDL_TRUE,SDL_MapRGB(LoadSurface->format,0,0xFF,0xFF));
		//Create texture from surface-tạo kết cấu từ mặt nạ
		newTexture=SDL_CreateTextureFromSurface(gRenderer,LoadSurface);
		if(newTexture==NULL){
			printf("Unable to create texture from %s! SDL Error: %s\n",path.c_str(),SDL_GetError());
			return false;
		}
		else {
			//Get image dimensions-lấy kích thước hình ảnh
			mWidth=LoadSurface->w;
			mHeight=LoadSurface->h;
		}
	}
	//Return success-trả về thành công
	mTexture=newTexture;
	return mTexture!=NULL;
}

void LTexture::free(){
	//Free texture if it exists-giải phóng kết cấu nếu nó tồn tại
	if(mTexture!=NULL){
		SDL_DestroyTexture(mTexture);
		mTexture=NULL;
		mWidth=0;
		mHeight=0;
	}
}

void LTexture::render(int x, int y){
	//set renderding space and render-đặt vùng kết xuất và kết xuất
	SDL_Rect renderQuad = {x,y,mWidth,mHeight};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
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
    //Loading success flag-Biến đánh dấu thành công
    bool success = true;

    //Load Foo' texture-Tải kết cấu Foo'
    if( !gFooTexture.loadFromFile( "media/medialec10/foo8.png" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    
    //Load background texture-	Tải kết cấu nền
    if( !gBackgroundTexture.loadFromFile( "media/medialec10/background.png"))
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gFooTexture.free();
    gBackgroundTexture.free();

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
				//Render backgrund- kết xuất nền
				gBackgroundTexture.render( 0, 0 );
				//Render Foo'- kết xuất Foo'
				gFooTexture.render( 240, 00 );
				

				
				//update screen-câp nhật màn hình
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL- hủy các tài nguyên và đóng SDL
	close();

	return 0;
}