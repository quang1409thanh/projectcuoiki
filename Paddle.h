
class Paddle
{
    public:
		//The dimensions of the dot
		static const int PADDLE_WIDTH = 128;
		static const int PADDLE_HEIGHT = 21;

		//Maximum axis velocity of the dot
		static const int PADDLE_VEL = 10;

		//Initializes the variables
		Paddle();

		//Takes key presses and adjusts the dot's velocity
		void handleEventPaddle( SDL_Event& e );

		//Moves the dot and checks collision
		void moveP();

		//Shows the dot on the screen
		void renderP();

		int getPosXP();
		int getPosYP();
		int getVelXP();
		int getVelYP();
    private:
		//The X and Y offsets of the dot
		int mPosXP, mPosYP;

		//The velocity of the dot
		int mVelXP, mVelYP;
		
		//Dot's collision box
		SDL_Rect mPaddle;
};


int Paddle::getPosXP(){
	return mPosXP;
}
int Paddle::getPosYP(){
	return mPosYP;
}
int Paddle::getVelXP(){
	return mVelXP;
}
int Paddle::getVelYP(){
	return mVelYP;
}

Paddle::Paddle(){
	mPosXP = SCREEN_WIDTH/2 - PADDLE_WIDTH/2;
	mPosYP = (SCREEN_HEIGHT-100) - PADDLE_HEIGHT;
	mVelXP = 0;
	mVelYP = 0;
	mPaddle.w = PADDLE_WIDTH;
	mPaddle.h = PADDLE_HEIGHT;
}

void Paddle::handleEventPaddle( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelYP -= PADDLE_VEL; break;
            // case SDLK_DOWN: mVelYP += PADDLE_VEL; break;
            case SDLK_LEFT: mVelXP -= PADDLE_VEL; break;
            case SDLK_RIGHT: mVelXP += PADDLE_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            // case SDLK_UP: mVelYP += PADDLE_VEL; break;
            // case SDLK_DOWN: mVelYP -= PADDLE_VEL; break;
            case SDLK_LEFT: mVelXP += PADDLE_VEL; break;
            case SDLK_RIGHT: mVelXP -= PADDLE_VEL; break;
        }
    }
}
void Paddle::moveP(){
    //Move the dot left or right
    mPosXP += mVelXP;
	mPaddle.x = mPosXP;

    //If the dot collided or went too far to the left or right
			if( ( mPosXP < 0 ) || ( mPosXP + PADDLE_WIDTH > SCREEN_WIDTH )  )
				{
					//Move back
					mPosXP -= mVelXP;
					mPaddle.x = mPosXP;
					}

    //Move the dot up or down
    mPosYP += mVelYP;
	mPaddle.y = mPosYP;

    //If the dot collided or went too far up or down
	
			 if( ( mPosYP < 0 ) || ( mPosYP + PADDLE_HEIGHT > (SCREEN_HEIGHT-100) ) )
				{
					//Move back
					mPosYP -= mVelYP;
					mPaddle.y = mPosYP;
					}
}
//Starts up SDL and creates window
void Paddle::renderP(){
	//Render paddle
	gPaddleTexture.render(mPosXP, mPosYP);
}
