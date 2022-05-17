class LButton2
{
    private:
        //Top left position
        SDL_Point mPosition;

        //Currently used global sprite
        LButtonSprite mCurrentSprite;
		// 2 trang thái của Button	
		LTexture texture[4];

        bool on;
    public:
        //Initializes internal variables
        LButton2();

        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        void handleEvent( SDL_Event* e );
        void update_Status();

        //Shows button sprite
        void render();

		void set_texture(std::string s,const int &n);

		void freeB();

		LButtonSprite getStatus();

		void freeStatus();


};

LButtonSprite LButton2::getStatus() {
	return mCurrentSprite;
}


LButton2::LButton2()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    on=true;
}

void LButton2::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton2::handleEvent( SDL_Event* e )
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
        else if( x > mPosition.x + BUTTON_WIDTH2 )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT2 )
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
            }
        }
    }
}
void LButton2::update_Status() {
		if (mCurrentSprite == BUTTON_SPRITE_MOUSE_DOWN && on) {
			on = false;
			freeStatus();
            music=false;
            sfx=false;
            std::cout<<"am thanh da tat"<<music<<sfx<<std::endl;
            setup_Sound_Off(music,sfx);

		}
		if (mCurrentSprite == BUTTON_SPRITE_MOUSE_DOWN && !on) {
			on = true;
			freeStatus();
            music=true;
            sfx=true;
            std::cout<<"am thanh da bat"<<music<<sfx<<std::endl;
            setup_Sound_Off(music,sfx);
            
		}
	}
void LButton2::render()
{
   //Show current button sprite
    
	if(mCurrentSprite == BUTTON_SPRITE_MOUSE_OUT && on){
        texture[0].render(mPosition.x, mPosition.y,&gSpriteClips2[0]);
    }
    else if(mCurrentSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION && on)
        {
            texture[1].render(mPosition.x, mPosition.y,&gSpriteClips2[1]);
            //setup_Sound_Off(music,sfx);
        }
    else if(mCurrentSprite == BUTTON_SPRITE_MOUSE_OUT && !on)

        texture[2].render(mPosition.x, mPosition.y,&gSpriteClips2[2]);

    else if(mCurrentSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION  && !on)
        {
            texture[3].render(mPosition.x, mPosition.y,&gSpriteClips2[3]);
            //setup_Sound_On(music,sfx);
        }
}

void LButton2::set_texture(std::string path,const int &n) {
	texture[n].loadFromFile(path);
			gSpriteClips2[ 0 ].x = 0;
			gSpriteClips2[ 0].y = 0;
			gSpriteClips2[ 0 ].w = BUTTON_WIDTH2;
			gSpriteClips2[ 0 ].h = BUTTON_HEIGHT2;
            gSpriteClips2[ 1 ].x = 179;
			gSpriteClips2[ 1 ].y = 0;
			gSpriteClips2[ 1 ].w = BUTTON_WIDTH2;
			gSpriteClips2[ 1 ].h = BUTTON_HEIGHT2;
            gSpriteClips2[ 2 ].x = 0;
			gSpriteClips2[ 2 ].y = 0;
			gSpriteClips2[ 2 ].w = BUTTON_WIDTH2;
			gSpriteClips2[ 2 ].h = BUTTON_HEIGHT2;
            gSpriteClips2[ 3 ].x = 179;
			gSpriteClips2[ 3 ].y = 0;
			gSpriteClips2[ 3 ].w = BUTTON_WIDTH2;
			gSpriteClips2[ 3 ].h = BUTTON_HEIGHT2;
}



void LButton2::freeStatus() {
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}
LButton2 gButtonsfx;
// chưa làm được cái button 2 trạng thái nghe mùi toang rồi