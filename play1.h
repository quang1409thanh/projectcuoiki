#pragma once
#include"loadhighscore.h"
#include"Init_Bricklv1.h"
#include"render_Brick.h"
std::string reset(){
	// dot.restart();
	// paddle.restart();
	// init_bricklv1();
	COUNT_DIES=2;
	count_Broken_Bricks=0;
}
std::string lose();
std::string pause();
std::string main_menu();
std::string sound();
std::string about();
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Back.handleEvent(&e);
			//gButtonSfxon.handleEvent(&e);
			//gButtonSfxoff.handleEvent(&e);
			gButtonsfx.handleEvent(&e);
			gButtonmusic.handleEvent(&e);

		}
			std::cout<<music<<"  "<<sfx<<std::endl;
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
		gButtonsfx.render();
		gButtonmusic.render();
		gButton1_Back.render();
		if(gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton1_Back.freeStatus();
			quit=true;
			return "menu";
		}
		// if(gButtonSfxoff.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
		// 	quit=true;
		// 	setup_Sound_Off(music,sfx);
		// 	gButtonSfxoff.freeStatus();
			
		// }
		
		
		//Update screen
		SDL_RenderPresent(gRenderer);

	}
}

std::string win(){
    //Main loop flag
	std::cout<<"win"<<std::endl;
	bool quit = false;

	//Event handler
	SDL_Event e;
    std::stringstream timeTextLose;
	std::stringstream high_Score;
	SDL_Color textColor = DEFAULT_COLOR;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton[RESTART].handleEvent(&e);
			gButton[MAIN_MENU].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			
		}
		timeTextLose.str("");
		timeTextLose << "YOU_SCORE:: " << count_Broken_Bricks ;
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
		gGameWin.render(10, 100);
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
		
        gFPSTextTexture.render(55,10);
		ghigh_Score.render(0, 50);
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
	Brick brick5[TOTAL_BRICKSLV5];
	Init_Bricklv5(brick5);
	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move5(brick5,TOTAL_BRICKSLV5);
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
		gTextTexture.loadFromRenderedText( "Level 5 ", textColor );
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
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0x00);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		//gBgTexturelv2.render(0, 0);
		//Render dot
        // if(fpsTimer.getTicks()==500){
        //     i++;
        //     while(i>4) i-=4;

        // }
		dot.render(1);
		paddle.renderP();
		i++;
		// gPowerC.render(i);
		
		// gPowerS.render(i);
		render_Brick_Lv5(brick5);
		while(i>4) i-=4;
		gButton1_Pause.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3+TOTAL_BRICKSLV4+TOTAL_BRICKSLV5)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset();
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
	Brick brick4[TOTAL_BRICKSLV4];
	Init_Bricklv4(brick4);
	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move(brick4,TOTAL_BRICKSLV4);
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
		gTextTexture.loadFromRenderedText( "Level 4 ", textColor );
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
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		//gBgTexturelv2.render(0, 0);
		//Render dot
        if(fpsTimer.getTicks()==500){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i);
		paddle.renderP();
		render_Brick_Lv4(brick4);
		gButton1_Pause.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3+TOTAL_BRICKSLV4)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset();
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
	Brick brick3[TOTAL_BRICKSLV3];
	Init_Bricklv3(brick3);
	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

		}	
		//Move the dot and check collision
		dot.move(brick3,TOTAL_BRICKSLV3);
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
		gTextTexture.loadFromRenderedText( "Level 3 ", textColor );
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
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		//gBgTexturelv2.render(0, 0);
		//Render dot
        if(fpsTimer.getTicks()==500){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i);
		paddle.renderP();
		render_Brick_Lv3(brick3);
		gButton1_Pause.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2+TOTAL_BRICKSLV3)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset();
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
	bool quit = false;
	//Event handler
	SDL_Event e;
	Brick brick2[TOTAL_BRICKSLV2];
	Init_Bricklv2(brick2);
	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

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
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		//gBgTexturelv2.render(0, 0);
		//Render dot
        if(fpsTimer.getTicks()==500){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i);
		paddle.renderP();
		render_Brick_Lv2(brick2);
		gButton1_Pause.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==(TOTAL_BRICKSLV1+TOTAL_BRICKSLV2)*50){// chú ý sửa chỗ này 
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset();
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
	COUNT_DIES=DIES;
	//Event handler
	SDL_Event e;
	Brick brick1[TOTAL_BRICKSLV1];
	Init_Bricklv1(brick1);
	//Angle of rotation
	double degrees = 0;
	if(music){
		Mix_PlayMusic(music_Play, -1);
	}

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//The dot that will be moving around on the screen
	// Dot dot;
	SDL_Color textColor = WHITE_COLOR;

	//The frames per second timer
	LTimer fpsTimer;

	//In memory text stream
	std::stringstream timeText;
	

	//Start counting frames per second
	int countedFrames = 0;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton1_Pause.handleEvent(&e);

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
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		// Render the bg
		
		//gBgTexture.render(0, 0);
		//Render dot
        if(fpsTimer.getTicks()==500){
            i++;
            while(i>4) i-=4;

        }
		dot.render(i);
		paddle.renderP();
		render_Brick_Lv1(brick1);
		gButton1_Pause.render();
		//gButton1_Reset.render();
		gBgLv1.render(0, 0);// hiện thị khung để chơi 
		//Render current frame
		gTextTexture.render(0, 10);// LV
		gFPSTextTexture.render(23, 551);// ĐIỂM
		ghigh_Score.render(150,28);

		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			Mix_HaltMusic();
			return "lose";
		}
		if(count_Broken_Bricks==TOTAL_BRICKSLV1*50){
			quit = true;
			//return "quit";
			SDL_Delay(100);
			dot.reset();
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
			//return "pause";
		}
		
}
}

std::string lose() {
	std::cout<<"lose"<<std::endl;
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
    std::stringstream timeTextLose;
	std::stringstream high_Score;
	SDL_Color textColor = DEFAULT_COLOR;
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
				return "quit";
				quit = true;
				
			}
			//Handle input for the dot
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton[RESTART].handleEvent(&e);
			gButton[MAIN_MENU].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			gButton1_Back.handleEvent(&e);
		}
        timeTextLose.str("");
		timeTextLose << "YOU_SCORE:: " << count_Broken_Bricks ;
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
		gButton1_Back.render();
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
		else if(gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton1_Back.freeStatus();
			quit=true;
			return "menu";
		}
		else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN)
		{
			gButton[EXIT].freeStatus();
			quit=true;
			return "quit";
		}

        gFPSTextTexture.render(55,10);
		ghigh_Score.render(0, 50);
		gGameOverTexture.render(10, 100);
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
	SDL_Color textColor = RED_COLOR;
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
				return "quit";
			}
			//Handle input for the dot
			// dot.handleEvent(e);
			// paddle.handleEventPaddle(e);
			gButton[ABOUT].handleEvent(&e);
			gButton[GAME_PLAY].handleEvent(&e);
			gButton[EXIT].handleEvent(&e);
			gButton[SOUND].handleEvent(&e);
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);
		

		gBg_Mainmenu[0].render(0, 0);
		gBg_Mainmenu[1].render(0, 0);
		gButton[ABOUT].render();
		gButton[GAME_PLAY].render();
		gButton[EXIT].render();
		gButton[SOUND].render();
		

		if(gButton[GAME_PLAY].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
        	//std::cout<<"GAME_PLAY"<<std::endl;
			gButton[GAME_PLAY].freeStatus();
			quit=true;
			//Mix_HaltMusic();
			// chỗ này chỉ để test level thôi
			return "playlv1";
           
   			//return "playlv1";
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
			//music_Menu=NULL;
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
		close();
		return "menu";

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
			//Handle input for the dot
			 gButton1_Back.handleEvent(&e);

		}
		// //Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		gBg_Mainmenu[1].render(0, 0);
		gBg_About.render(0, 300);
		gButton1_Back.render();

		if(gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
			gButton1_Back.freeStatus();
			quit=true;
			return "menu";
		}
		//Update screen
		SDL_RenderPresent(gRenderer);
	}
}
// std::string Exit(&){
// 	//Main loop flag
// }
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);
			gButton[RESUME].handleEvent(&e);
			gButton[SOUND].handleEvent(&e);
			//gButton[MAIN_MENU].handleEvent(&e);
			//gButton[EXIT].handleEvent(&e);

		}
		//Clear screen
		

		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		//SDL_RenderClear(gRenderer);
		gButton[RESUME].render();
		gButton[SOUND].render();
		//gButton[MAIN_MENU].render();
		//gButton[EXIT].render();
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
		// if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
		// 	gButton[EXIT].freeStatus();
		// 	quit=true;
		// 	return "quit";
		// }
		//Update screen
		SDL_RenderPresent(gRenderer);
	}

}
