#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
#include "LTexture.h"
#include "LTimer.h"
#include "LButton.h"

#include "Brick.h"
#include "Paddle.h"

#include "Dot.h"

#include"varcommon.h"

#include "funcommon.h"

std::string lose();
std::string pause();
std::string main_menu();
std::string sound();
std::string about();

std::string playlv1();
std::string playlv2();
std::string playlv3();
std::string playlv4();
std::string playlv5();


//==== hàm hiện thị màn hình âm thanh
std::string sound(){
	std::cout<<"sound"<<std::endl;
	bool quit = false;

	//Event handler
	SDL_Event e;
	
	//While application is running
	
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			dot.handleEvent(e,paddle);
			paddle.handleEventPaddle(e);
			gButton1_Back.handleEvent(&e);
			gButtonsfx.handleEvent(&e);
			gButtonmusic.handleEvent(&e);

		}
		//Clear screen
		
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xF0);
		SDL_RenderClear(gRenderer);

		if(gButtonmusic.getStatus()==BUTTON_SPRITE_MOUSE_DOWN&&gButtonmusic.get_on()) {
		music=!music;
		gButtonmusic.set_on(false);
		gButtonmusic.freeStatus();
		}
		if(gButtonmusic.getStatus()==BUTTON_SPRITE_MOUSE_DOWN&&!gButtonmusic.get_on()) {
		music=!music;
		gButtonmusic.set_on(true);
		gButtonmusic.freeStatus();
		}
		if(gButtonsfx.getStatus()==BUTTON_SPRITE_MOUSE_DOWN&&gButtonsfx.get_on()) {
		sfx=!sfx;
		gButtonsfx.set_on(false);
		gButtonsfx.freeStatus();
		}
	
		if(gButtonsfx.getStatus()==BUTTON_SPRITE_MOUSE_DOWN&&!gButtonsfx.get_on()) {
		sfx=!sfx;
		gButtonsfx.set_on(true);
		gButtonsfx.freeStatus();
		}
		if(gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton1_Back.freeStatus();
			quit=true;
			return "menu";
		}
		

		//Render objects
		gButtonsfx.render(gRenderer);
		gButtonmusic.render(gRenderer);
		gButton1_Back.render(gRenderer);
		//Update screen
		SDL_RenderPresent(gRenderer);
		

	}
}

// hiện thị màn hình khi thắng

std::string win(){
    //Main loop flag
	std::cout<<"win"<<std::endl;
	bool quit = false;
	//Event handler
	SDL_Event e;

	// hiện thị điểm khi thua
    std::stringstream timeTextWin;

	// hiện thị điểm cao
	std::stringstream high_Score;

	// màu sắc của các texture load từ chữ
	SDL_Color textColor = DEFAULT_COLOR;
	

	// điều kiện để có âm thanh 
	if(music){
		Mix_PlayMusic(music_GameWin, -1);
	}
	
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			gButton[RESTART].handleEvent(&e);
			gButton[MAIN_MENU].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			
		}

		// điểm khi ở màn hình thắng
		timeTextWin.str("");
		timeTextWin << "YOU_SCORE:: " << count_Broken_Bricks ;

		// điểm cao 

		high_Score.str("");
		high_Score << "HIGH SCORE:: " << loadhighscore();

		// load texture từ chữ
		if (!gScoreTexture.loadFromRenderedText(timeTextWin.str().c_str(), textColor,gRenderer,gFont))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText(high_Score.str().c_str(), textColor,gRenderer,gFont))
		{
			printf("Unable to render FPS texture!\n");
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render objects
		gButton[RESTART].render(gRenderer);
		gButton[MAIN_MENU].render(gRenderer);
		gButton[EXIT].render(gRenderer);
		gGameWin.render(10, 100,gRenderer);
		
        gScoreTexture.render(20,10,gRenderer);
		ghigh_Score.render(0, 50,gRenderer);


		if(gButton[RESTART].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton[RESTART].freeStatus();
			count_Broken_Bricks=0;
			quit=true;
			return "playlv1";
			
		}
		else if(gButton[MAIN_MENU].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			gButton[MAIN_MENU].freeStatus();
			count_Broken_Bricks=0;
			quit=true;
			return "menu";
		}
		else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton[EXIT].freeStatus();
			quit=true;
			return "quit";
		}
		
		//Update screen
		SDL_RenderPresent(gRenderer);
		
	}
}

std::string playlv5() {
	//Main loop flag
	std::cout<<"playlv5"<<std::endl;
	bool quit = false;
	//Event handler
	SDL_Event e;

	// khởi tạo brick
	Brick brick5[TOTAL_BRICKSLV5];
	Init_Bricklv5(brick5);
	
	//Angle of rotation
	double degrees = 0;

	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	SDL_Color textColor = WHITE_COLOR;


	//In memory text stream
	std::stringstream timeText;
	

	//While application is running
	
	while (!quit)
	{   
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			if(dot.getVelX()==0&&dot.getVelY()==0){
				dot.handleEvent(e,paddle);
			}
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move5(brick5,TOTAL_BRICKSLV5,paddle,count_Broken_Bricks,COUNT_DIES,sfx,ballcollision,brickcollision); 
		paddle.moveP();

		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 5 ", textColor ,gRenderer,gFont);
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gScoreTexture.loadFromRenderedText1(timeText.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0x00);
		SDL_RenderClear(gRenderer);

		// Render objects
		dot.render(1,gRenderer);  

		//render paddle
		renderPaddle();
		
		render_Brick_Lv5(brick5);
		
		gButton1_Pause.render(gRenderer);
		gBgLv1.render(0, 0,gRenderer);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10,gRenderer);// LV
		gScoreTexture.render(23, 551,gRenderer);// ĐIỂM
		ghigh_Score.render(150,28,gRenderer);// ĐIỂM CAO

		//Update screen
		SDL_RenderPresent(gRenderer);
		
		
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3+TOTAL_BRICKSLV4+TOTAL_BRICKSLV5-6)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset(paddle);
			return "win";
		}
		if(gButton1_Pause.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			velPauseX=dot.getVelX();
			velPauseY=dot.getVelY();
			dot.set_mVelX(0);
			dot.set_mVelY(0);
			Mix_HaltMusic();
			gButton1_Pause.freeStatus();
			pause();
		}
		
}
}
std::string playlv4() {
	//Main loop flag
	std::cout<<"playlv4"<<std::endl;
	bool quit = false;

	//Event handler
	SDL_Event e;

	// khởi tạo brick 
	Brick brick4[TOTAL_BRICKSLV4];
	Init_Bricklv4(brick4);

	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	// màu của font chữ 
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	
	fpsTimer.start();

   	int i=0;
	//While application is running
	while (!quit)
	{   
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			if(dot.getVelX()==0&&dot.getVelY()==0){
				dot.handleEvent(e,paddle);
			}
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move(brick4,TOTAL_BRICKSLV4,paddle,count_Broken_Bricks,COUNT_DIES,sfx,ballcollision,brickcollision); 
		paddle.moveP();


		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 4 ", textColor,gRenderer,gFont );
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gScoreTexture.loadFromRenderedText1(timeText.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);

		// render object
		//Render dot
        if(fpsTimer.getTicks()%1000==0){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i,gRenderer);
		renderPaddle();
		render_Brick_Lv4(brick4);
		gButton1_Pause.render(gRenderer);
		gBgLv1.render(0, 0,gRenderer);// hiện thị khung để chơi 
		gTextTexture.render(0, 10,gRenderer);// LV
		gScoreTexture.render(23, 551,gRenderer);// ĐIỂM
		ghigh_Score.render(150,28,gRenderer);// điểm cao 

		//Update screen
		SDL_RenderPresent(gRenderer);
		
		
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3+TOTAL_BRICKSLV4)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset(paddle);
			return "playlv5";
		}
		if(gButton1_Pause.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			velPauseX=dot.getVelX();
			velPauseY=dot.getVelY();
			dot.set_mVelX(0);
			dot.set_mVelY(0);
			Mix_HaltMusic();
			gButton1_Pause.freeStatus();
			pause();
		}
		
}
}
std::string playlv3() {
	//Main loop flag
	std::cout<<"playlv3"<<std::endl;
	bool quit = false;

	//Event handler
	SDL_Event e;

	//khởi tạo brick
	Brick brick3[TOTAL_BRICKSLV3];
	Init_Bricklv3(brick3);

	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;


	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	


   	int i=0;
	//While application is running
	while (!quit)
	{   
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			if(dot.getVelX()==0&&dot.getVelY()==0){
				dot.handleEvent(e,paddle);
			}
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move(brick3,TOTAL_BRICKSLV3,paddle,count_Broken_Bricks,COUNT_DIES,sfx,ballcollision,brickcollision);
		
		paddle.moveP();

		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}

		// điểm cao 
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 3 ", textColor ,gRenderer,gFont);
		
		// điểm và lượt chơi còn lại 
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;

		//Render text
		if (!gScoreTexture.loadFromRenderedText1(timeText.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render objects
		// thay đổi màu quả bóng được
        if(fpsTimer.getTicks()%1000==0){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i,gRenderer);
		renderPaddle();
		render_Brick_Lv3(brick3);
		gButton1_Pause.render(gRenderer);
		gBgLv1.render(0, 0,gRenderer);// hiện thị khung để chơi 

		gTextTexture.render(0, 10,gRenderer);// LV
		gScoreTexture.render(23, 551,gRenderer);// ĐIỂM
		ghigh_Score.render(150,28,gRenderer);// điểm cao 
		
		//Update screen
		SDL_RenderPresent(gRenderer);
		

		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset(paddle);
			return "playlv4";
		}
		if(gButton1_Pause.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			velPauseX=dot.getVelX();
			velPauseY=dot.getVelY();
			dot.set_mVelX(0);
			dot.set_mVelY(0);
			Mix_HaltMusic();
			gButton1_Pause.freeStatus();
			pause();
		}
		
}
}

std::string playlv2() {
	//Main loop flag
	std::cout<<"playlv2"<<std::endl;
	// 
	bool quit = false;
	//Event handler
	SDL_Event e;

	// khởi tạo brick
	Brick brick2[TOTAL_BRICKSLV2];
	Init_Bricklv2(brick2);

	//Angle of rotation
	double degrees = 0;

	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;


	SDL_Color textColor = WHITE_COLOR;


	//In memory text stream
	std::stringstream timeText;
	

   	int i=0;
	//While application is running
	while (!quit)
	{   
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			if(dot.getVelX()==0&&dot.getVelY()==0){
				dot.handleEvent(e,paddle);
			}
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move(brick2,TOTAL_BRICKSLV2,paddle,count_Broken_Bricks,COUNT_DIES,sfx,ballcollision,brickcollision);
		paddle.moveP();
		
		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 2 ", textColor ,gRenderer,gFont);
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gScoreTexture.loadFromRenderedText1(timeText.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render objects
		dot.render(i,gRenderer);
		renderPaddle();
		render_Brick_Lv2(brick2);
		gButton1_Pause.render(gRenderer);
		gBgLv1.render(0, 0,gRenderer);// hiện thị khung để chơi 

		gTextTexture.render(0, 10,gRenderer);// LV
		gScoreTexture.render(23, 551,gRenderer);// ĐIỂM
		ghigh_Score.render(150,28,gRenderer);// điểm cao

		//Update screen
		SDL_RenderPresent(gRenderer);
		

		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset(paddle);
			return "playlv3";
		}
		if(gButton1_Pause.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			velPauseX=dot.getVelX();
			velPauseY=dot.getVelY();
			dot.set_mVelX(0);
			dot.set_mVelY(0);
			Mix_HaltMusic();
			gButton1_Pause.freeStatus();
			pause();
		}
		
}
}

std::string playlv1() {
	//Main loop flag
	std::cout<<"playlv1"<<std::endl;
	bool quit = false;

	// số lượt chơi còn lại
	COUNT_DIES=DIES;
	//Event handler
	SDL_Event e;

	// khởi tạo các viên gạch 
	Brick brick1[TOTAL_BRICKSLV1];
	Init_Bricklv1(brick1);

	//Angle of rotation
	double degrees = 0;

	// điều kiện để có âm thanh khi chơi

	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	
	fpsTimer.start();

   	int i=0;
	//While application is running
	while (!quit)
	{   
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			if(dot.getVelX()==0&&dot.getVelY()==0){
			dot.handleEvent(e,paddle);
			}
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);
			
		}	
		//Move the dot and check collision
		dot.move(brick1,TOTAL_BRICKSLV1,paddle,count_Broken_Bricks,COUNT_DIES,sfx,ballcollision,brickcollision); 
		paddle.moveP();

		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}

		// điểm cao 
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 1 ", textColor, gRenderer,gFont);
		
		// điểm
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;

		// số lượt chơi còn lại 
        timeText << " Live:: " << COUNT_DIES;

		//Render text
		if (!gScoreTexture.loadFromRenderedText1(timeText.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor,gRenderer,gFont_HighScore))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);

        if(fpsTimer.getTicks()%1000==0){
            i++;
            while(i>4) i-=4;
        }
	
		// render object
		// thay đổi màu của quả bóng theo thời gian 
		dot.render(i,gRenderer);
		renderPaddle();
		render_Brick_Lv1(brick1);
		gButton1_Pause.render(gRenderer);
		gBgLv1.render(0, 0,gRenderer);// hiện thị khung để chơi 

		gTextTexture.render(0, 10,gRenderer);// LV
		gScoreTexture.render(23, 551,gRenderer);// ĐIỂM
		ghigh_Score.render(150,28,gRenderer);// điểm cao 

		//update screen
		SDL_RenderPresent(gRenderer);
		

		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==TOTAL_BRICKSLV1*50){
			
			quit = true;
			SDL_Delay(100);
			dot.reset(paddle);
			return "playlv2";
		}
		if(gButton1_Pause.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			velPauseX=dot.getVelX();
			velPauseY=dot.getVelY();
			dot.set_mVelX(0);
			dot.set_mVelY(0);
			Mix_HaltMusic();
			gButton1_Pause.freeStatus();
			pause();
		}
		
}
}

std::string lose() {
	std::cout<<"lose"<<std::endl;
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;

	// hiện thị điểm thua
    std::stringstream timeTextLose;

	// hiện thị điểm cao 
	std::stringstream high_Score;

	// màu phông chữ 
	SDL_Color textColor = GREEN_COLOR;

	// điểu kiện để bật âm thanh game thua
	if(music){
	Mix_PlayMusic(music_GameOver, -1 );
	}
	
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				return "quit";
				quit = true;
				
			}
			gButton[RESTART].handleEvent(&e);
			gButton[MAIN_MENU].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
		}

		// điểm khi thua 
        timeTextLose.str("");
		timeTextLose << "YOU_SCORE:: " << count_Broken_Bricks ;

		// điểm cao 
		high_Score.str("");
		high_Score << "HIGH SCORE:: " << loadhighscore();

		// load texture từ chữ
		if (!gScoreTexture.loadFromRenderedText(timeTextLose.str().c_str(), textColor,gRenderer,gFont))
        {
            printf("Unable to render FPS texture!\n");
        }
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText(high_Score.str().c_str(), textColor,gRenderer,gFont))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		
		//render objects
		gButton[RESTART].render(gRenderer);
		gButton[MAIN_MENU].render(gRenderer);
		gButton[EXIT].render(gRenderer);
        gScoreTexture.render(0,50,gRenderer);
		ghigh_Score.render(0, 90,gRenderer);
		gGameOverTexture.render(00, 150,gRenderer);


		if(gButton[RESTART].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton[RESTART].freeStatus();
			count_Broken_Bricks=0;
			quit=true;
			return "playlv1";
			
		}
		else if(gButton[MAIN_MENU].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{	
			gButton[MAIN_MENU].freeStatus();
			count_Broken_Bricks=0;
			quit=true;
			return "menu";
		}
		else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton[EXIT].freeStatus();
			quit=true;
			return "quit";
		}


		//Update screen
		SDL_RenderPresent(gRenderer);
		
}
}

std::string main_menu(){
	std::cout<<"main_menu"<<std::endl;
    //Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;


	if(music){

	Mix_PlayMusic(music_Menu, -1 );
	}
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			gButton[ABOUT].handleEvent(&e);
			gButton[GAME_PLAY].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			gButton[SOUND].handleEvent(&e);
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		
		//render objects
		gBg_Mainmenu[0].render(0, 0,gRenderer);
		gBg_Mainmenu[1].render(0, 0,gRenderer);
		gButton[ABOUT].render(gRenderer);
		gButton[GAME_PLAY].render(gRenderer);
		gButton[EXIT].render(gRenderer);
		gButton[SOUND].render(gRenderer);
		

		if(gButton[GAME_PLAY].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
        	
			gButton[GAME_PLAY].freeStatus();
			quit=true;

			return "playlv1";
           
    	}
		else if(gButton[ABOUT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			quit=true;
			gButton[ABOUT].freeStatus();
			Mix_HaltMusic();
			return "about";
		}
		else if(gButton[SOUND].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			quit=true;
			gButton[SOUND].freeStatus();

			Mix_HaltMusic();
			return "sound";
		}
		else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			std::cout<<"Exit"<<std::endl;
			gButton[EXIT].freeStatus();
			quit=true;
			return "quit";
		}

		//Update screen
		SDL_RenderPresent(gRenderer);
		
	}
}
std::string about(){
	std::cout<<"about"<<std::endl;
    //Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	//std::stringstream timeText_About;
	SDL_Color textColor = BLACK_COLOR;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			 gButton1_Back.handleEvent(&e);

		}
		// //Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//render objects
		gBg_Mainmenu[1].render(0, 0,gRenderer);
		gBg_About.render(0, 300,gRenderer);
		gButton1_Back.render(gRenderer);

		if(gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton1_Back.freeStatus();
			quit=true;
			return "menu";
		}
		//Update screen
		SDL_RenderPresent(gRenderer);
		
	}
}

std::string pause(){
	std::cout<<"pause"<<std::endl;
	bool quit = false;

	//Event handler
	SDL_Event e;
	
	//While application is running
	
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				return "quit";
			}
			//Handle input for the dot
			dot.handleEvent(e,paddle);
			paddle.handleEventPaddle(e);
			gButton[RESUME].handleEvent(&e);
			gButton[SOUND].handleEvent(&e);

		}

		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		//SDL_RenderClear(gRenderer);

		//render objects
		gButton[RESUME].render(gRenderer);
		gButton[SOUND].render(gRenderer);


		if(gButton[RESUME].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton[RESUME].freeStatus();
			quit=true;
			dot.set_mVelX(velPauseX);
			dot.set_mVelY(velPauseY);
			if(music){
				Mix_PlayMusic(music_Play, -1);
			}
			
			return "playlv1";
		}
		if(gButton[SOUND].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton[SOUND].freeStatus();
			// quit=true;
			// return "sound";
			sound();
		}

		//Update screen
		SDL_RenderPresent(gRenderer);
		
		
	}

}

