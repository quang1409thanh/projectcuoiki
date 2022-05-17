class Power{
	public:
		//The dimensions of the dot
		static const int POWER_WIDTH = 48;
		static const int POWER_HEIGHT = 48;

		//Maximum axis velocity of the dot
		static const int POWER_VEL = 0;

		//Initializes the variables
		Power();

		//Takes key presses and adjusts the dot's velocity
		void handleEventBrick( SDL_Event& e );

		//Moves the dot and checks collision
		void movePower( );

		//Shows the dot on the screen
		void renderPower(char color);//n lưu ý chõ này ko sử dụng được kiểu string

		int getPosXPOWER();
		int getPosYPOWER();
		int getVelXPOWER();
		int getVelYPOWER();
		void free();

		void set_Position_POWER( int x, int y );
		
        void set_gPower_Texture(std::string path,const int &n);
		
		//SDL_Rect getColliderPOWER();
	private:
		//The X and Y offsets of the dot
		int mPosXPOWER, mPosYPOWER;

		//The velocity of the dot
		int mVelXPOWER, mVelYPOWER;
		
		//Dot's collision box
		//SDL_Rect mPOWER;

        LTexture gPower[4];
		
		//int mR, mG, mB, mA, mS, mT;
};
Power::Power(){
	mPosXPOWER=-100;
	mPosYPOWER=-100;
	mVelXPOWER=0;
	mVelYPOWER=0;
	//mPOWER={mPosXPOWER,mPosYPOWER,POWER_WIDTH,POWER_HEIGHT};
}

int Power::getPosXPOWER(){
	return mPosXPOWER;
}
int Power::getPosYPOWER(){
	return mPosYPOWER;
}
int Power::getVelXPOWER(){
	return mVelXPOWER;
}
int Power::getVelYPOWER(){
	return mVelYPOWER;
}

Power Power::set_POWER(int x, int y,int vely){
	mPosXPOWER=x;
	mPosYPOWER=y; 
	mVelYPOWER=vely;
    return *this;
}
Power Power::set_mPosXPOWER(int x){
    mPosXPOWER=x;
    return *this;
}

void Power::renderB(char color){
	switch (color){
		case 'r':
			gBricksTextureRed.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'b':
			gBricksTextureBlue.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'g':
			gBricksTextureGreen.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'd':
			gBricksTexturDearkgreen.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'i':
			gBricksTextureIndigo.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'o':
			gBricksTextureOrange.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'p':
			gBricksTexturePink.render(mPosXPOWER,mPosYPOWER);
			break;
		case 's':
			gBricksTextureSolid.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'v':
			gBricksTextureViolet.render(mPosXPOWER,mPosYPOWER);
			break;
		case 'y' :
			gBricksTextureYellow.render(mPosXPOWER,mPosYPOWER);
			break;
		
	}
}
void Power::free(){

}