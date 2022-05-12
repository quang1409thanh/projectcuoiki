#pragma once
#include"loadhighscore.h"
#include"Init_Bricklv1.h"
#include"render_Brick.h"
void reset(){
	// dot.restart();
	// paddle.restart();
	// init_bricklv1();
	COUNT_DIES=2;
	count_Broken_Bricks=0;
}
void lose();
void win();
void main_menu();
void sound();
void about();
void sound(){
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
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Back.handleEvent(&e);
			gButtonSfxon.handleEvent(&e);
			gButtonSfxoff.handleEvent(&e);

		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		gButton1_Back.render();
		//gButtonSfxon.render();
		gButtonSfxoff.render();
		//Update screen
		SDL_RenderPresent(gRenderer);
	}
}

void win(){
    //Main loop flag
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
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);

		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		gGameWin.render(10, 100);
		//Update screen
		SDL_RenderPresent(gRenderer);
	}
}


void playlv2() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Angle of rotation
	double degrees = 0;

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor =RED_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
	fpsTimer.start();

   Brick brick2[TOTAL_BRICKSLV2];
   Init_Bricklv2(brick2);
   if(music){
   Mix_PlayMusic(music_Play, -1 );
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
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);
			gButton1_Reset.handleEvent(&e);

		}

		//Move the dot and check collision
		dot.move(brick2,TOTAL_BRICKSLV2);
		//dot.ball_brick_collision(brick1,TOTAL_BRICKSLV1);
		paddle.moveP();
		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}
		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 2 ", textColor );
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText1(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		gBgTexturelv2.render(0, 0);
		//Render dot
		dot.render('r');
		paddle.renderP();
		render_Brick_Lv2(brick2);
		gButton1_Pause.render();
		gButton1_Reset.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//gTextbox.render(0, 0);
		//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
		// SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		// SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_HEIGHT - 100); // thừa ko cần vẽ vạch này
		
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			SDL_Delay(100);
			lose();
			break;
		}
	}
}
void playlv1() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

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

   Brick brick1[TOTAL_BRICKSLV1];
   Init_Bricklv1(brick1);
   if(music){
   Mix_PlayMusic(music_Play, -1 );
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
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);
			gButton1_Reset.handleEvent(&e);

		}

		//Move the dot and check collision
		dot.move(brick1,TOTAL_BRICKSLV1);
		//dot.ball_brick_collision(brick1,TOTAL_BRICKSLV1);
		paddle.moveP();
		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}
		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH_SCORE:: " << loadhighscore();
		gTextTexture.loadFromRenderedText( "Level 1 ", textColor );
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText1(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText1(high_Score.str().c_str(), textColor))
		{
			printf("er!\n");
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		gBgTexture.render(0, 0);
		//Render dot
		dot.render('t');
		paddle.renderP();
		render_Brick_Lv1(brick1);
		gButton1_Pause.render();
		gButton1_Reset.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//gTextbox.render(0, 0);
		//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
		// SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		// SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_HEIGHT - 100); // thừa ko cần vẽ vạch này
		
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			SDL_Delay(100);
			lose();
			break;
		}
		if(count_Broken_Bricks==TOTAL_BRICKSLV1*50){
			quit = true;
			SDL_Delay(100);
			dot.reset();
			playlv2();
	}
}
}
void lose() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
    std::stringstream timeTextLose;
	std::stringstream high_Score;
	SDL_Color textColor = { 0, 0, 0, 255 };
	//While application is running
	if(music){
	Mix_PlayMusic(music_GameOver, -1 );
	}
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton[RESTART].handleEvent(&e);
			gButton[MAIN_MENU].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
		}
        timeTextLose.str("");
		timeTextLose << "SCORE:: " << count_Broken_Bricks ;
		if(count_Broken_Bricks>loadhighscore()){
			sethighscore(count_Broken_Bricks);
		}
		high_Score.str("");
		high_Score << "HIGH SCORE:: " << loadhighscore();
		if (!gFPSTextTexture.loadFromRenderedText(timeTextLose.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText(high_Score.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		
		
		gButton[RESTART].render();
		gButton[MAIN_MENU].render();
		gButton[EXIT].render();

        gFPSTextTexture.render(0,  20);
		ghigh_Score.render(0, 50);
		gGameOverTexture.render(10, 100);
		//Update screen
		SDL_RenderPresent(gRenderer);
}
}

void main_menu(){
    //Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	SDL_Color textColor = { 250, 0, 0, 255 };
	std::stringstream timeText;
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
			}
			//Handle input for the dot
			// dot.handleEvent(e);
			// paddle.handleEventPaddle(e);
			gButton[ABOUT].handleEvent(&e);
			gButton[GAME_PLAY].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			gButton[SOUND].handleEvent(&e);
		}
		
		timeText.str("");
		timeText<<"BRICKGAME";
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		

		//gBg_Mainmenu.render(0, 0);
		gButton[ABOUT].render();
		gButton[GAME_PLAY].render();
		gButton[EXIT].render();
		gButton[SOUND].render();

		gFPSTextTexture.render(0, 50);    
		if(gButton[GAME_PLAY].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
        	std::cout<<"GAME_PLAY"<<std::endl;
    	}
		else if(gButton[ABOUT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			std::cout<<"About"<<std::endl;
		}
		else if(gButton[SOUND].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			std::cout<<"Sound"<<std::endl;
		}
		else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			std::cout<<"Exit"<<std::endl;
		}
		//Update screen
		SDL_RenderPresent(gRenderer);
}
}
void about(){
    //Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	//std::stringstream timeText_About;
	SDL_Color textColor = RED_COLOR;

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
			}
			//Handle input for the dot
			 gButton1_Back.handleEvent(&e);

		}
		// timeText_About.str("");
		// timeText_About<<"ABOUT"<<std::endl;
		// timeText_About<<"This game is created by: "<<std::endl;
		// timeText_About<<"Nguyen Quang Thanh"<<std::endl;
		if (!gAbout[0].loadFromRenderedText("ABOUT", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[1].loadFromRenderedText("This game is created by:", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[2].loadFromRenderedText("Nguyen Quang Thanh", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[3].loadFromRenderedText("Graphics Library used:", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[4].loadFromRenderedText("SDL2_devel", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[5].loadFromRenderedText("SDL2_img_devel", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[6].loadFromRenderedText("SDL2_ttf_devel", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!gAbout[7].loadFromRenderedText("SDL2_mixer_devel", textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		gGameWin.render(10, 150);
		for(int i=0;i<8;i++){
		gAbout[i].render(10, 400+30*i);
		}
		gButton1_Back.render();
		//Update screen
		SDL_RenderPresent(gRenderer);

	}
}
// void Exit(&){
// 	//Main loop flag
// }