struct Circle
{
	int x, y;
	int r;
};

class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 21;
		static const int DOT_HEIGHT = 21;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 6;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and checks collision
		void move( Brick brick[],int n);

		//Shows the dot on the screen
		void render(char color);
        void reset();
        void set_gDot_Texture(std::string path,const int &n);
        void ball_brick_collision(Brick brick[],int n);

        int set_mVelY(int& y);
		void restart();
        int getX();
        int getY();
    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		
		//Dot's collision box
		Circle mCollider;

        void shiftColliders();

        LTexture gDot[5];
};

double distanceSquared( int x1, int y1, int x2, int y2 )
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX*deltaX + deltaY*deltaY;
}
bool checkCollision( Circle& a, Brick& b )
{
    //Closest point on collision box
    int cX, cY;

    //Find closest x offset
    if( a.x < b.getPosXB() )
    {
        cX = b.getPosXB();
    }
    else if( a.x > b.getPosXB() + b.BRICK_WIDTH )
    {
        cX =b.getPosXB() + b.BRICK_WIDTH;
    }
    else
    {
        cX = a.x;
    }

    //Find closest y offset
    if( a.y < b.getPosYB() )
    {
        cY = b.getPosYB();
    }
    else if( a.y > b.getPosYB()+ b.BRICK_HEIGHT )
    {
        cY = b.getPosYB()+ b.BRICK_HEIGHT;
    }
    else
    {
        cY = a.y;
    }

    //If the closest point is inside the circle
    if( distanceSquared( a.x, a.y, cX, cY ) < a.r * a.r )
    {
        //This box and the circle have collided
        return true;
    }

    //If the shapes have not collided
    return false;
}

Dot::Dot()
{
    //Initialize the offsets
    mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
    mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;

	//Set collision box dimension
	mCollider.r = DOT_WIDTH/2;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    //Move collider relative to the circle
    shiftColliders();
}
void Dot::shiftColliders()
{
	//Align collider to center of dot
	mCollider.x = mPosX;
	mCollider.y = mPosY;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
			case SDLK_1: {
				mVelX=-DOT_VEL;
				mVelY=-DOT_VEL;
			}
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
			case SDLK_1: {
				mVelX=-DOT_VEL;
				mVelY=-DOT_VEL;
			}
        }
    }
}
void Dot::ball_brick_collision(Brick brick[],int n){
    bool a;
    for(int i=0;i<n;i++){
            a=checkCollision(mCollider,brick[i]);
            if(a==true){
            brick[i]=brick[i].setBrick_mPosXB(30000);
            //delete_brick_count++;
            Mix_PlayChannel( -1, brickcollision, 0 );
            count_Broken_Bricks++;
            }
            a=false;
        }
}
void Dot::move(Brick brick[],int n ){
	int PADDLE_HEIGHT=paddle.PADDLE_HEIGHT;
	int PADDLE_WIDTH=paddle.PADDLE_WIDTH;
	int batx=paddle.getPosXP();
	int baty=paddle.getPosYP();
    //Move the dot left or right

    //If the dot collided or went too far to the left or right
    //va chạm với viên gạch
    mPosX += mVelX;
	shiftColliders();

    //If the dot collided or went too far to the left or right
    for(int i=0;i<n;i++){
	if(  checkCollision( mCollider, brick[i] ) )
    {
        //Move back
        mVelX*=-1;
        mVelY*=-1;
        bool a=checkCollision(mCollider,brick[i]);
        if(a==true){
        brick[i]=brick[i].setBrick_mPosXB(30000);
        //delete_brick_count++;
        Mix_PlayChannel( -1, brickcollision, 0 );
        count_Broken_Bricks++;
        }
		shiftColliders();
        std::cout<<count_Broken_Bricks;
		std::cout<<": lr"<<std::endl;
    }
    }
    // va chạm với cạnh bên trái và cạnh bên phải
    if( ( mPosX < 0 )  ) {
        mVelX *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }
    if(( mPosX + DOT_WIDTH > SCREEN_WIDTH )){
        mVelX *= -1;
        Mix_PlayChannel(-1,ballcollision,0);
    }

    if((mPosY>=baty)&&(mPosX==batx-DOT_WIDTH||mPosX==batx+PADDLE_WIDTH)){
        mVelX*=-1;
    }
    //Move the dot up or down
    mPosY += mVelY;
	shiftColliders();

    //If the dot collided or went too far up or down
    for(int i=0;i<n;i++){
    if(  checkCollision( mCollider, brick[i] ) )
    {
        //Move back
        mVelY*=-1;
		shiftColliders();
        bool a=checkCollision(mCollider,brick[i]);
        if(a==true){
        brick[i]=brick[i].setBrick_mPosXB(30000);
        //delete_brick_count++;
        Mix_PlayChannel( -1, brickcollision, 0 );
        count_Broken_Bricks++;
        }
        std::cout<<count_Broken_Bricks;
		std::cout<<": ud"<<std::endl;
    }
    }
    
    // va chạm với cạnh trên
    if( mPosY < 0 ) {
        mVelY *= -1;
        //Mix_PlayChannel(-1,ballcollision,0);
    }
    // va chạm với cạnh dưới
	if(mPosY + DOT_HEIGHT > (SCREEN_HEIGHT-100) ){
        
		reset();
		SDL_Delay(50);
		COUNT_DIES--;
	}
    // va chạm với paddle
    if(mPosY+DOT_HEIGHT>=baty&&mPosX>=batx&&mPosX<=batx+PADDLE_WIDTH){
        mVelY*=-1;
		//Mix_PlayChannel(-1,ballcollision,0);
    }
    
}
void Dot::render(char color)
{
    switch(color){
        case 'r':
        gDot[0].render( mPosX, mPosY ,&gDotRect[0]);
        break;
        case 'p':
        gDot[1].render( mPosX, mPosY ,&gDotRect[1]);
        break;
        case 't':
        gDot[2].render( mPosX, mPosY ,&gDotRect[2]);
        break;
        case 'b':
        gDot[3].render( mPosX, mPosY ,&gDotRect[3]);
        break;
        case 'g':
        gDot[4].render( mPosX, mPosY ,&gDotRect[4]);
        break;
    }
}
void Dot::set_gDot_Texture(std::string path,const int &n) {
    gDot[n].loadFromFile(path);
    for(int i=0;i<5;i++){
        gDotRect[i]={i*DOT_WIDTH,0,DOT_WIDTH,DOT_HEIGHT};
    }
}
int Dot :: getX() {
    return mPosX;
}
int Dot::getY() {
    return mPosY;
}
void Dot:: reset(){
        //Initialize the offsets
    mPosX = paddle.getPosXP()+paddle.PADDLE_WIDTH/2-DOT_WIDTH/2;
    mPosY = SCREEN_HEIGHT-100 - DOT_HEIGHT-paddle.PADDLE_HEIGHT;

	//Set collision box dimension
	mCollider.r = DOT_WIDTH/2;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    shiftColliders();
}