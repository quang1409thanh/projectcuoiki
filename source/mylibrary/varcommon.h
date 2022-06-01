#pragma once
// số viên gạch của từng level
const int TOTAL_BRICKSLV1 =49;
const int TOTAL_BRICKSLV2 = 29;
const int TOTAL_BRICKSLV3 =34;
const int TOTAL_BRICKSLV4 = 33;
const int TOTAL_BRICKSLV5 =28;


// số lượt chơi còn lại 
const int DIES=2;
int COUNT_DIES=DIES;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

// khởi tạo music và sound
Mix_Chunk *ballcollision=NULL;
Mix_Chunk *brickcollision=NULL;
Mix_Music *music_Menu=NULL;
Mix_Music *music_Play=NULL;
Mix_Music *music_GameWin=NULL;
Mix_Music *music_GameOver=NULL;

//Globally used font
TTF_Font *gFont = NULL;
TTF_Font *gFont_HighScore = NULL;

// điểm số của trò chơi
int count_Broken_Bricks=0;

// số màu của viên gạch
const int TOTAL_COLOR_BRICK = 10;

// khai báo 2 biến để giữa vel lúc pause
int velPauseX=0;
int velPauseY=0;



// điểm cao 
std::stringstream high_Score;

//một số màu mặc định
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

// biến để lưu trạng thái của âm thanh
bool music=true;
bool sfx=true;

int FPS=60;


//Scene textures
// khai báo các biến LTexture để load texture từ hình ảnh quả bóng (dot)
LTexture gDotTexture;

// khai báo các biến LTexture để load texture từ hình ảnh mái chèo (paddle)
LTexture gPaddleTexture;

//// khai báo các biến LTexture để load texture từ hình ảnh viên gạch (brick    )
LTexture gBricksTexture[ TOTAL_COLOR_BRICK];
//Rendered texture

// hiện thị level game
LTexture gTextTexture;

//khai báo texture điểm
LTexture gScoreTexture;

// load hình ảnh khi gameover
LTexture gGameOverTexture;

// load hình ảh khi game win 
LTexture gGameWin;

// khai báo texture điểm cao
LTexture ghigh_Score;

// load hình ảnh bg ở main_menu
LTexture gBg_Mainmenu[2];

// load hình ảnh about game
LTexture gBg_About;

//load hình ảnh khung chơi
LTexture gBgLv1;// khung chơi


//================các biến thuộc button================

LButton gButton[14];


//====================khai báo các biến sử của LButton1====================
LButton1 gButton1_Pause;
LButton1 gButton1_Back;

//====khai báo biến thuộc button này====
LButton2 gButtonsfx;
LButton2 gButtonmusic;



Paddle paddle;

Dot dot(paddle);
