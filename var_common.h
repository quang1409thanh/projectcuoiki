//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;
const int SCREEN_LEFT=20;
const int SCREEN_RIGHT=20;
const int SCREEN_TOP=60;
const int SCREEN_BOTTOM=70;

const int BRICK_ROWS = 5;
const int BRICK_COLUMNS= 5;
const int TOTAL_BRICKSLV1 =40;
const int TOTAL_BRICKSLV2 = 35;
const int TOTAL_BRICKSLV3 =34;
const int TOTAL_BRICKSLV4 = 30;
const int TOTAL_BRICKSLV5 =34;
const int TOTAL_BRICKSLV6 = 30;
const int TOTAL_BRICKSLV7 =34;
const int TOTAL_BRICKSLV8 = 30;
const int TOTAL_BRICKSLV9 =34;
const int TOTAL_BRICKSLV10 = 30;
const int TOTAL_BRICKSLV11 =34;
const int TOTAL_BRICKSLV12 = 30;
const int TOTAL_BRICKSLV13 =34;
const int TOTAL_BRICKSLV14 = 30;
const int TOTAL_BRICKSLV15 =34;
const int DIES=2;
int COUNT_DIES=DIES;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
Mix_Chunk *ballcollision=NULL;
Mix_Chunk *brickcollision=NULL;
Mix_Music *music_Menu=NULL;
Mix_Music *music_Play=NULL;
Mix_Music *music_GameWin=NULL;
Mix_Music *music_GameOver=NULL;
//Globally used font
TTF_Font *gFont = NULL;
TTF_Font *gFont_HighScore = NULL;

int count_Broken_Bricks=0;
//Button constants
const int BUTTON_WIDTH = 179;
const int BUTTON_HEIGHT = 71;
const int TOTAL_BUTTONS = 4;
//Button constants
const int BUTTON_WIDTH1 = 40;
const int BUTTON_HEIGHT1 = 40;
const int TOTAL_BUTTONS1 = 4;
const int BUTTON_WIDTH2 = 179;
const int BUTTON_HEIGHT2 = 71;
const int TOTAL_BUTTONS2 = 4;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};
enum Status {
	MAIN_MENU = 0,
	GAME_PLAY = 1,
    GAME_PLAY2 = 2,
    ABOUT=3,
    SOUND=4,
	WIN = 5,
	LOSE = 6,
	PAUSE = 7,
    RESTART = 8,
	EXIT = 9,
    TOTAL_STATUS = 10
};
enum color{
    red=0,
    pink=1,
    purple=2,
    blue=3,
    green=4,
    TOTAL_COLOR=5
};
//Mouse button sprites
SDL_Rect gSpriteClips[4];
SDL_Rect gSpriteClips1[4];
SDL_Rect gSpriteClips2[4];
SDL_Rect gDotRect[5];
std::stringstream high_Score;
const SDL_Color CYAN_COLOR = {0, 255, 255};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color ORANGE_COLOR = {255, 165, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};
const SDL_Color LIME_COLOR = {0, 255, 0};
const SDL_Color PURPLE_COLOR = {128, 0, 128};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREEN_COLOR = {0, 128, 0};
const SDL_Color DEFAULT_COLOR = BLACK_COLOR;