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
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
Mix_Chunk *ballcollision=NULL;
Mix_Chunk *brickcollision=NULL;
//Globally used font
TTF_Font *gFont = NULL;
int count_Broken_Bricks=0;
bool gOver=false;
//Texture wrapper class
#include"const.h"

#include"LTexture.h"
#include"LTimer.h"
#include"Paddle.h"
#include"Brick.h"
#include"Dot.h"
#include"khoitao.h"
// cần phải sửa lại một só chỗ để cho khi thay đổi thứ tự include thì nó vẫn có thể chạy được
// bước tiếp theo tạo thành cái game hoàn chỉnh sau đó sẽ tạo menu
void runing(){
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
				timeText << "SCORE:: " << count_Broken_Bricks<<"| Live:: "<<fpsTimer.getTicks()/1000.f;
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

				//Update screen
				if(gOver) {
					    SDL_Surface *go=IMG_Load("gameover.png");
						SDL_Texture *gotexture=SDL_CreateTextureFromSurface(gRenderer,go);
						SDL_Rect gorect={0,0,800,600};
						SDL_RenderCopy(gRenderer,gotexture,NULL,NULL);
						SDL_RenderPresent(gRenderer);
						SDL_Delay(2000);
						//Destroy();
					}
				SDL_RenderPresent( gRenderer );
				++countedFrames;
			}
        }
	}
	//Free resources and close SDL
	close();
}