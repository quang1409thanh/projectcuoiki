#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "LTexture.h"
#include "Brick.h"
#include "Paddle.h"

// màu của quả bóng (dot)
enum color
{
	red = 0,
	pink = 1,
	purple = 2,
	blue = 3,
	green = 4,
	TOTAL_COLOR = 5
};

// khởi tạo cáu trúc hình tròn cho quả bóng
struct Circle
{
	int x, y;
	int r;
};

// khởi tạo class cho đối tượng quả bóng

class Dot
{
public:
	// The dimensions of the dot
	static const int DOT_WIDTH = 21;
	static const int DOT_HEIGHT = 21;

	// Maximum axis velocity of the dot
	static const int DOT_VEL = 4;

	// Initializes the variables
	Dot(Paddle paddle);

	// Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event &e, Paddle paddle);

	// Moves the dot and checks collision
	void move(Brick brick[], int n, Paddle paddle, int &count_Broken_Bricks, int &COUNT_DIES, bool &sfx, Mix_Chunk *ballcollision, Mix_Chunk *brickcollision);
	void move5(Brick brick[], int n, Paddle paddle, int &count_Broken_Bricks, int &COUNT_DIES, bool &sfx, Mix_Chunk *ballcollision, Mix_Chunk *brickcollision);

	// Shows the dot on the screen
	void render(const int &color, SDL_Renderer *&gRenderer);
	void reset(Paddle paddle);

	void set_gDot_Texture(std::string path, const int &n, SDL_Renderer *&gRenderer);

	int set_mVelY(int y);
	int set_mVelX(int x);
	int getVelX();
	int getVelY();

	int getX();
	int getY();
	int setPosX(int x);
	int setPosY(int y);

	void free();

private:
	// The X and Y offsets of the dot
	int mPosX, mPosY;

	// The velocity of the dot
	int mVelX, mVelY;

	// Dot's collision box
	Circle mCollider;

	void shiftColliders(); // khởi tạo hình tròn cho quả bóng

	LTexture gDot[5];
};