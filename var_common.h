//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 650;

const int BRICK_ROWS = 5;
const int BRICK_COLUMNS= 5;
const int TOTAL_BRICKSLV1 = 15;
const int TOTAL_BRICKSLV2 = 10;
int COUNT_DIES=5;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
Mix_Chunk *ballcollision=NULL;
Mix_Chunk *brickcollision=NULL;
//Globally used font
TTF_Font *gFont = NULL;

int count_Broken_Bricks=0;
//Button constants
const int BUTTON_WIDTH = 179;
const int BUTTON_HEIGHT = 71;
const int TOTAL_BUTTONS = 4;
//Button constants
const int BUTTON_WIDTH1 = 40;
const int BUTTON_HEIGHT1 = 40;
const int TOTAL_BUTTONS1 = 4;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

//Mouse button sprites
SDL_Rect gSpriteClips[4];
SDL_Rect gSpriteClips1[4];