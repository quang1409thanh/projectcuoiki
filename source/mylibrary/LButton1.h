// build class button1==========================================================
class LButton1
{
    public:
        //Initializes internal variables
        LButton1();

        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        void handleEvent( SDL_Event* e );
    
        //Shows button sprite
        void render();

		void set_texture(std::string s,const int &n);

		void freeB();

		LButtonSprite getStatus();

		void freeStatus();


    private:
        //Top left position
        SDL_Point mPosition;

        //Currently used global sprite
        LButtonSprite mCurrentSprite;
		// 2 trang thái của Button	
		LTexture texture[4];
};

//====================khai báo các biến sử của LButton1====================
LButton1 gButton1_Pause;
LButton1 gButton1_Back;
LButton1 gButton1_Reset;

//=====================các hàm thành viên của LButton1=====================

LButtonSprite LButton1::getStatus() {
	return mCurrentSprite;
}


LButton1::LButton1()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton1::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton1::handleEvent( SDL_Event* e )
{
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
		//Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < mPosition.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH1 )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT1 )
        {
            inside = false;
        }
		//Mouse is outside button
        if( !inside )
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;
            
                case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;
                
                case SDL_MOUSEBUTTONUP:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break; //thừa
            }
        }
    }
}

void LButton1::render()
{
   //Show current button sprite
	switch (mCurrentSprite) {
	case BUTTON_SPRITE_MOUSE_OUT: {
		texture[0].render(mPosition.x, mPosition.y,&gSpriteClips1[ mCurrentSprite ] );
		break;
	}
	case BUTTON_SPRITE_MOUSE_OVER_MOTION: {
		texture[1].render(mPosition.x, mPosition.y,&gSpriteClips1[ mCurrentSprite ] );
	}
	case BUTTON_SPRITE_MOUSE_DOWN: {
		texture[2].render(mPosition.x, mPosition.y,&gSpriteClips1[ mCurrentSprite ] );
	}
	case BUTTON_SPRITE_MOUSE_UP: {
		texture[3].render(mPosition.x, mPosition.y,&gSpriteClips1[ mCurrentSprite ] );
	}
	}
}

void LButton1::set_texture(std::string path,const int &n) {
	texture[n].loadFromFile(path);
			gSpriteClips1[ 0 ].x = 0;
			gSpriteClips1[ 0].y = 0;
			gSpriteClips1[ 0 ].w = BUTTON_WIDTH1;
			gSpriteClips1[ 0 ].h = BUTTON_HEIGHT1;
	
			gSpriteClips1[ 1 ].x = 40;
			gSpriteClips1[ 1 ].y = 0;
			gSpriteClips1[ 1 ].w = BUTTON_WIDTH1;
			gSpriteClips1[ 1 ].h = BUTTON_HEIGHT1;

			gSpriteClips1[ 2 ].x = 80;
			gSpriteClips1[ 2 ].y = 0;
			gSpriteClips1[ 2 ].w = BUTTON_WIDTH1;
			gSpriteClips1[ 2 ].h = BUTTON_HEIGHT1;
			gSpriteClips1[ 3 ].x = 0;
			gSpriteClips1[ 3 ].y = 0;
			gSpriteClips1[ 3 ].w = BUTTON_WIDTH1;
			gSpriteClips1[ 3 ].h = BUTTON_HEIGHT1;
}



void LButton1::freeStatus() {
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
}
void LButton1::freeB() {
    texture[0].free();
    texture[1].free();
    texture[2].free();
    texture[3].free();
}
