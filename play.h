#pragma once


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
void lose() {
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
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
			dot.handleEvent(e);
			paddle.handleEventPaddle(e);

		}
        // timeText.str("");
		// timeText << "SCORE:: " << count_Broken_Bricks ;
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

        gFPSTextTexture.render(0, SCREEN_HEIGHT - 30);
		gGameOverTexture.render(10, 100);
		//Update screen
		SDL_RenderPresent(gRenderer);

	}
}
void play() {
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


	Brick brick[BRICK_ROWS][BRICK_COLUMNS];
	for (int i = 0; i < BRICK_ROWS; i++)
	{
		for (int j = 0; j < BRICK_COLUMNS; j++)
		{
			brick[i][j] = brick[i][j].setBrick(20 + i * brick[i][j].BRICK_WIDTH, j * brick[i][j].BRICK_HEIGHT, 0, 0, brick[i][j].BRICK_WIDTH, brick[i][j].BRICK_HEIGHT);
		}
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

		// //Set text to be rendered
		timeText.str("");
		timeText << "SCORE:: " << count_Broken_Bricks ;
        timeText << " Live:: " << COUNT_DIES;
		//Render text
		if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
		{
			printf("Unable to render FPS texture!\n");
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x0F, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render dot
		dot.render();
		paddle.renderP();
		for (int i = 0; i < BRICK_ROWS; i++)
		{
			for (int j = 0; j < BRICK_COLUMNS; j++)
			{
				brick[i][j].renderB();
			}
		}
		//Draw blue horizontal line- kết xuất màu xanh vào đường ngang
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_HEIGHT - 100);
		//Render current frame
		gTextTexture.render(0, SCREEN_HEIGHT - 70);
		gFPSTextTexture.render(0, SCREEN_HEIGHT - 30);
		//gGameOverTexture.render(10,100);
		//Update screen
		SDL_RenderPresent(gRenderer);
		++countedFrames;
		if (COUNT_DIES < 0) {
			SDL_Delay(100);
			lose();
			break;
		}
        else if(count_Broken_Bricks==BRICK_ROWS*BRICK_COLUMNS)
        {
            SDL_Delay(100);
            win();
            break;
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
			play();
		}
	}
}