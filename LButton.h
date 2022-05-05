//The mouse button
class LButton
{
    public:
        //Initializes internal variables
        LButton();

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

LButtonSprite LButton::getStatus() {
	return mCurrentSprite;
}


LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent( SDL_Event* e )
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
        else if( x > mPosition.x + BUTTON_WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT )
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

void LButton::render()
{
   //Show current button sprite
	switch (mCurrentSprite) {
	case BUTTON_SPRITE_MOUSE_OUT: {
		texture[0].render(mPosition.x, mPosition.y,&gSpriteClips[ mCurrentSprite ] );
		break;
	}
	case BUTTON_SPRITE_MOUSE_OVER_MOTION: {
		texture[1].render(mPosition.x, mPosition.y,&gSpriteClips[ mCurrentSprite ] );
	}
	case BUTTON_SPRITE_MOUSE_DOWN: {
		texture[2].render(mPosition.x, mPosition.y,&gSpriteClips[ mCurrentSprite ] );
	}
	case BUTTON_SPRITE_MOUSE_UP: {
		texture[3].render(mPosition.x, mPosition.y,&gSpriteClips[ mCurrentSprite ] );
	}
	}
}

void LButton::set_texture(std::string path,const int &n) {
	texture[n].loadFromFile(path);
			gSpriteClips[ 0 ].x = 0;
			gSpriteClips[ 0].y = 0;
			gSpriteClips[ 0 ].w = BUTTON_WIDTH;
			gSpriteClips[ 0 ].h = BUTTON_HEIGHT;
	
			gSpriteClips[ 1 ].x = 179;
			gSpriteClips[ 1 ].y = 0;
			gSpriteClips[ 1 ].w = BUTTON_WIDTH;
			gSpriteClips[ 1 ].h = BUTTON_HEIGHT;

			gSpriteClips[ 2 ].x = 358;
			gSpriteClips[ 2 ].y = 0;
			gSpriteClips[ 2 ].w = BUTTON_WIDTH;
			gSpriteClips[ 2 ].h = BUTTON_HEIGHT;
			gSpriteClips[ 3 ].x = 0;
			gSpriteClips[ 3 ].y = 0;
			gSpriteClips[ 3 ].w = BUTTON_WIDTH;
			gSpriteClips[ 3 ].h = BUTTON_HEIGHT;
}



void LButton::freeStatus() {
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
}
