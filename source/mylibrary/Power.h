class Power{
	public:
		//The dimensions of the dot
		static const int POWER_WIDTH = 48;
		static const int POWER_HEIGHT = 48;

		//Maximum axis velocity of the dot
		static const int POWER_VEL = 10;

		//Initializes the variables
		Power();

		//Takes key presses and adjusts the dot's velocity
		void handleEventPOWER( SDL_Event& e );

		//Moves the dot and checks collision
		void movePower( );

		//Shows the dot on the screen
		void renderPower(char color);//n lưu ý chõ này ko sử dụng được kiểu string

		int getPosXPOWER();
		int getPosYPOWER();
		int getVelXPOWER();
		int getVelYPOWER();
		
		SDL_Rect getColliderPOWER();// muốn phát triển thay đổi kích thước của game 
		void setPosXPOWER(int& x);
		void setPosYPOWER(int& y);
		void setVelXPOWER(int& x);
		void setVelYPOWER(int& y);
		void free();

		void set_Position_POWER( int x, int y );
		void set_POWER(int x, int  y,int vely);
		Power set_mPosXPOWER(int x);
		
        void set_gPower_Texture(std::string path,const int &n);
		
		void render(const int &n);
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
	mPosXPOWER=100;
	mPosYPOWER=100;
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

void Power::setPosXPOWER(int& x){
	mPosXPOWER=x;
}
void Power::setPosYPOWER(int& y){
	mPosYPOWER=y;
}
void Power::setVelXPOWER(int& x){
	mVelXPOWER=x;
}
void Power::setVelYPOWER(int& y){
	mVelYPOWER=y;
}
void Power::set_POWER(int x, int y,int vely){
	mPosXPOWER=x;
	mPosYPOWER=y; 
	mVelYPOWER=vely;
}
Power Power::set_mPosXPOWER(int x){
    mPosXPOWER=x;
    return *this;
}
void Power::set_gPower_Texture(std::string path,const int &n){
	gPower[n].loadFromFile(path);
	for(int i=0;i<4;i++){
		gPowerRect[i]={i*POWER_WIDTH,0,POWER_WIDTH,POWER_HEIGHT};
	}
}

void Power::movePower( ){
	//Move the dot left or right
	mPosXPOWER += mVelXPOWER;
	mPosYPOWER += mVelYPOWER;
	//mPOWER.x += mVelXPOWER;
	//mPOWER.y += mVelYPOWER;
}
void Power::render(const int& n)
{
    switch(n){
        case 0:
        gPower[0].render( mPosXPOWER, mPosYPOWER ,&gPowerRect[0]);
        break;
        case 1:
        gPower[1].render( mPosXPOWER, mPosYPOWER ,&gPowerRect[1]);
        break;
        case 2:
        gPower[2].render( mPosXPOWER, mPosYPOWER ,&gPowerRect[2]);
        break;
        case 3:
        gPower[3].render( mPosXPOWER, mPosYPOWER ,&gPowerRect[3]);
        break;
    }
}
void Power::free(){

}
Power gPowerC;
Power gPowerS;