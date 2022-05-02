
//Box collision detector
bool checkCollision( SDL_Rect a, Brick b );
//The dot that will move around on the screen

class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and checks collision
		void move( Brick brick[BRICK_ROWS][BRICK_COLUMNS] );

		//Shows the dot on the screen
		void render();
        void ball_brick_collision(Brick brick[BRICK_ROWS][BRICK_COLUMNS]);

        int set_mVelY(int& y);
    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		
		//Dot's collision box
		SDL_Rect mCollider;
};

Dot::Dot()
{
    //Initialize the offsets
    mPosX = SCREEN_WIDTH / 2 - DOT_WIDTH / 2;
    mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;

	//Set collision box dimension
	mCollider.w = DOT_WIDTH;
	mCollider.h = DOT_HEIGHT;

    //Initialize the velocity
    mVelX = 10;
    mVelY = 10;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}
void Dot::ball_brick_collision(Brick brick[BRICK_ROWS][BRICK_COLUMNS]){
    bool a;
    for(int i=0;i<BRICK_ROWS;i++){
        for(int j=0;j<BRICK_COLUMNS;j++){
            a=checkCollision(mCollider,brick[i][j]);
            if(a==true){
            brick[i][j]=brick[i][j].setBrick_mPosXB(30000);
            mVelY*=-1;
            //delete_brick_count++;
            }
            a=false;
        }
    }
}

void Dot::move( Brick brick[BRICK_ROWS][BRICK_COLUMNS] ){
	int PADDLE_HEIGHT=paddle.PADDLE_HEIGHT;
	int PADDLE_WIDTH=paddle.PADDLE_WIDTH;
	int batx=paddle.getPosXP();
	int baty=paddle.getPosYP();
    //Move the dot left or right
    mPosX += mVelX;
	mCollider.x = mPosX;
	
    //If the dot collided or went too far to the left or right
	for(int i=0;i<BRICK_ROWS;i++){
		for(int j=0;j<BRICK_COLUMNS;j++){
			if(checkCollision( mCollider, brick[i][j] ) )
				{
					//Move back
					Mix_PlayChannel(-1,brickcollision,0);
					mVelX*=-1;
					mVelY*=-1;
                    
				}
		}
	}
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) ) {
        mVelX *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }
	mPosY += mVelY;
	mCollider.y = mPosY;
    //Move the dot up or down
    // chỗ này di chuyển đúng nhưng âm thanh ko đúng

    //If the dot collided or went too far up or down
	for(int i=0;i<BRICK_ROWS;i++){
		for(int j=0;j<BRICK_COLUMNS;j++){
			 if( checkCollision( mCollider, brick[i][j] ) )
				{
					//Move back
					//count_Broken_Bricks++;
					Mix_PlayChannel(-1,brickcollision,0);
					count_Broken_Bricks++;
                    
				}
		}
	}
    if(( mPosY < 0 ) ) {
        mVelY *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }
	if (mPosY + DOT_HEIGHT > (SCREEN_HEIGHT-100)){
		gOver=true;
	}
	
	int ballscaling=PADDLE_HEIGHT;// hoặc bằng 20 check sau đoạn này 
    if(mPosY+ballscaling>=baty&&mPosY<=(SCREEN_HEIGHT-100)&&mPosX>=batx&&mPosX<=batx+PADDLE_WIDTH){
        mVelY*=-1;
		Mix_PlayChannel(-1,ballcollision,0);
    }
	// if(mPosY+ballscaling>baty&&mPosY<SCREEN_HEIGHT&&mPosX>batx&&mPosX<batx+PADDLE_WIDTH){
	// 	mVelX*=-1;
	// 	Mix_PlayChannel(-1,ballcollision,0);
	// }
	// ** lưu ý chỗ lỗi thì ko phải là trường hợp gameover hôm sau cần fix cho chuẩn xác
}
void Dot::render()
{
    //Show the dot
	gDotTexture.render( mPosX, mPosY );
}

// int Dot::set_mVelY(int& y){
//     mVelY=y;
//     return mVelY;
// }


// Brick brick;
// for(int i=1; i<=BRICK_ROWS; i++){
// 	for(int j=1; j<=BRICK_COLUMNS; j++){
// 		brick[i][j].setBrick(i*BRICK_WIDTH, j*BRICK_HEIGHT, 0, 0, BRICK_WIDTH, BRICK_HEIGHT);// có thể nên lấy từ file ra chỗ này
// 	}
// }
			
Dot dot;


bool checkCollision( SDL_Rect a, Brick b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.getPosXB();
    rightB = b.getPosXB() + b.BRICK_WIDTH;
    topB = b.getPosYB();
    bottomB = b.getPosYB()+ b.BRICK_HEIGHT;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}


