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
void playlv2();
void lose();
void win();
void main_menu();
void sound();
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

		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		gButton1_Back.render();
		
		//Update screen
		SDL_RenderPresent(gRenderer);
		if(gButton1_Back.getStatus() == BUTTON_SPRITE_MOUSE_OVER_MOTION)
		{
			SDL_Delay(100);
			main_menu();
			break;
		}
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
	std::stringstream high_Score;

	//Start counting frames per second
	int countedFrames = 0;
	fpsTimer.start();

   Brick brick[TOTAL_BRICKSLV1];
   Init_Bricklv1(brick);
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
		dot.move(brick);
		dot.ball_brick_collision(brick);
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
		high_Score << "HIGH SCORE:: " << loadhighscore();
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText(high_Score.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		gTextTexture.loadFromRenderedText( "level 1 ", textColor );
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render dot
		dot.render();
		paddle.renderP();
		render_Brick_Lv1(brick);
		gButton1_Pause.render();
		gButton1_Reset.render();
		//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_HEIGHT - 100);
		//Render current frame
		gTextTexture.render(0, SCREEN_HEIGHT -60);
		gFPSTextTexture.render(0, SCREEN_HEIGHT - 30);
		ghigh_Score.render(0, SCREEN_HEIGHT - 90);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			SDL_Delay(100);
			lose();
			break;
		}
        else if(count_Broken_Bricks>=TOTAL_BRICKSLV1){
		playlv2();
		break;
	}
	}
}

void playlv2() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	dot.reset();
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
	std::stringstream high_Score;

	//Start counting frames per second
	int countedFrames = 0;
	fpsTimer.start();

   Brick brick[TOTAL_BRICKSLV2];
   Init_Bricklv2(brick);
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
		dot.move(brick);
		dot.ball_brick_collision(brick);
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
		high_Score << "HIGH SCORE:: " << loadhighscore();
		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE LV2:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		if (!ghigh_Score.loadFromRenderedText(high_Score.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		gTextTexture.loadFromRenderedText( "level 2 ", textColor );
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render dot
		dot.render();
		paddle.renderP();
		render_Brick_Lv2(brick);
		gButton1_Pause.render();
		gButton1_Reset.render();
		//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_HEIGHT - 100);
		//Render current frame
		gTextTexture.render(0, SCREEN_HEIGHT -60);
		gFPSTextTexture.render(0, SCREEN_HEIGHT - 30);
		ghigh_Score.render(0, SCREEN_HEIGHT - 90);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			SDL_Delay(100);
			lose();
			break;
		}
        // else if(count_Broken_Bricks==TOTAL_BRICKSLV1){
        // {
        //     SDL_Delay(100);
        //     win();
        //     break;
        // }
	}
}
// void play(){
// 	//Main loop flag
// 	playlv1();
	
// }
void lose() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
    std::stringstream timeTextLose;
	std::stringstream high_Score;
	SDL_Color textColor = { 0, 0, 0, 255 };
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
			gButtonRestart.handleEvent(&e);
			gButtonMainmenu.handleEvent(&e);
			gButtonExit.handleEvent(&e);
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

		gButtonRestart.render();
		gButtonMainmenu.render();
		gButtonExit.render();

        gFPSTextTexture.render(0,  20);
		ghigh_Score.render(0, 50);
		gGameOverTexture.render(10, 100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		if(gButtonRestart.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			quit = true;

		}
		if(gButtonExit.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			quit = true;
		}
		if(gButtonMainmenu.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			quit = true;
		}
}
}

void main_menu(){
    //Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	SDL_Color textColor = { 250, 0, 0, 255 };
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
			}
			//Handle input for the dot
			// dot.handleEvent(e);
			// paddle.handleEventPaddle(e);
			gButtonAbout.handleEvent(&e);
			gButtonPlay.handleEvent(&e);
			gButtonExit.handleEvent(&e);
			gButtonSound.handleEvent(&e);

		}
		
		timeText.str("");
		timeText<<"BRICKGAME";
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		gButtonAbout.render();
		gButtonPlay.render();
		gButtonExit.render();
		gButtonSound.render();

		gFPSTextTexture.render(0, 50);
		//Update screen
		SDL_RenderPresent(gRenderer);
		if(gButtonPlay.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			SDL_Delay(200);
			quit=true;
			break;// quan trọng nếu ko có thì ko thể tắt được cửa sổ
		}
		if (gButtonExit.getStatus() == BUTTON_SPRITE_MOUSE_DOWN) {
			quit = true;
			//exit(0);
		}
		if (gButtonSound.getStatus() == BUTTON_SPRITE_MOUSE_DOWN) {
			sound();
			break;
		}
	}
}