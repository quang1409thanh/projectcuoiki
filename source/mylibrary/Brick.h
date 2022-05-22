
class Brick{
	public:
		//The dimensions of the dot
		static const int BRICK_WIDTH = 50;
		static const int BRICK_HEIGHT = 22;

		//Maximum axis velocity of the dot
		static const int BRICK_VEL = 0;

		//Initializes the variables
		Brick();

		//Takes key presses and adjusts the dot's velocity
		void handleEventBrick( SDL_Event& e );

		//Moves the dot and checks collision
		void moveB ();

		//Shows the dot on the screen
		void renderB(char color);//n lưu ý chõ này ko sử dụng được kiểu string

		int getPosXB();
		int getPosYB();
		int getVelXB();
		int getVelYB();
		
		void free();

		Brick setBrick_mPosXB(int x);

		Brick setBrick(int x, int y, int velx, int vely);

		LTexture gBricks;
		SDL_Rect getColliderB();
	private:
		//The X and Y offsets of the dot
		int mPosXB, mPosYB;

		//The velocity of the dot
		int mVelXB, mVelYB;
		
		LTexture gBrick_Texture[TOTAL_BRICKS];

};
Brick::Brick(){
	mPosXB=-100;
	mPosYB=-100;
	mVelXB=-100;
	mVelYB=-100;
	//mBrick={mPosXB,mPosYB,BRICK_WIDTH,BRICK_HEIGHT}; lưu ý nếu muốn phát triển game nếu thay đổi kích thước màn hình của game
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
// SDL_Rect Brick::getColliderB(){
// 	return mBrick;
// }

Brick Brick::setBrick(int x, int y, int velx, int vely){
	mPosXB=x;
	mPosYB=y;
	mVelXB=velx;
	mVelYB=vely;
	//mBrick={x,y,w,h};
    return *this;
}
Brick Brick::setBrick_mPosXB(int x){
    mPosXB=x;
    return *this;
}

void Brick::renderB(char color){
	switch (color){
		case 'r':
			gBricksTexture[RED].render(mPosXB,mPosYB);
			break;
		case 'b':
			gBricksTexture[BLUE].render(mPosXB,mPosYB);
			break;
		case 'g':
			gBricksTexture[GREEN].render(mPosXB,mPosYB);
			break;
		case 'd':
			gBricksTexture[DARK_GREEN].render(mPosXB,mPosYB);
			break;
		case 'i':
			gBricksTexture[INDIGO].render(mPosXB,mPosYB);
			break;
		case 'o':
			gBricksTexture[ORANGE].render(mPosXB,mPosYB);
			break;
		case 'p':
			gBricksTexture[PINK].render(mPosXB,mPosYB);
			break;
		case 's':
			gBricksTexture[SOLID].render(mPosXB,mPosYB);
			break;
		case 'v':
			gBricksTexture[VIOLET].render(mPosXB,mPosYB);
			break;
		case 'y' :
			gBricksTexture[YELLOW].render(mPosXB,mPosYB);
			break;
		
	}
}
void Brick::free(){
	gBricksTexture[BLUE].free();
	gBricksTexture[RED].free();
	gBricksTexture[GREEN].free();
	gBricksTexture[DARK_GREEN].free();
	gBricksTexture[INDIGO].free();
	gBricksTexture[ORANGE].free();
	gBricksTexture[PINK].free();
	gBricksTexture[SOLID].free();
	gBricksTexture[VIOLET].free();
	gBricksTexture[YELLOW].free();
	gGameOverTexture.free();
}