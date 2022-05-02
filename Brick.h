
class Brick{
	public:
		//The dimensions of the dot
		static const int BRICK_WIDTH = 80;
		static const int BRICK_HEIGHT = 35;

		//Maximum axis velocity of the dot
		static const int BRICK_VEL = 0;

		//Initializes the variables
		Brick();

		//Takes key presses and adjusts the dot's velocity
		void handleEventBrick( SDL_Event& e );

		//Moves the dot and checks collision
		void moveB( Brick **brick );

		//Shows the dot on the screen
		void renderB();

		int getPosXB();
		int getPosYB();
		int getVelXB();
		int getVelYB();

		Brick setBrick_mPosXB(int x);

		Brick setBrick(int x, int y, int velx, int vely, int w, int h);

		LTexture gBricks;
	private:
		//The X and Y offsets of the dot
		int mPosXB, mPosYB;

		//The velocity of the dot
		int mVelXB, mVelYB;
		
		//Dot's collision box
		SDL_Rect mBrick;
		
		//int mR, mG, mB, mA, mS, mT;
};
Brick::Brick(){
	mPosXB=100;
	mPosYB=100;
	mVelXB=0;
	mVelYB=0;
	mBrick={mPosXB,mPosYB,BRICK_WIDTH,BRICK_HEIGHT};
}

int Brick::getPosXB(){
	return mPosXB;
}
int Brick::getPosYB(){
	return mPosYB;
}
int Brick::getVelXB(){
	return mVelXB;
}
int Brick::getVelYB(){
	return mVelYB;
}


Brick Brick::setBrick(int x, int y, int velx, int vely, int w, int h){
	mPosXB=x;
	mPosYB=y;
	mVelXB=velx;
	mVelYB=vely;
	mBrick={x,y,w,h};
    return *this;
}
Brick Brick::setBrick_mPosXB(int x){
    mPosXB=x;
    return *this;
}

void Brick::renderB(){
	//Render the dot
	gBrickTexture.render(mPosXB, mPosYB);
}