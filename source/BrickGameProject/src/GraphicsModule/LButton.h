#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "LTexture.h"
#include <iostream>
// Trạng thái của chuột khi tương tác với button
enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

// Các trạng thái của game
enum Status
{
    MAIN_MENU = 0,
    GAME_PLAY = 1,
    GAME_PLAY2 = 2,
    GAME_PLAY3 = 3,
    GAME_PLAY4 = 4,
    GAME_PLAY5 = 5,
    ABOUT = 6,
    SOUND = 7,
    WIN = 8,
    LOSE = 9,
    RESUME = 10,
    PAUSE = 11,
    RESTART = 12,
    EXIT = 13,
    TOTAL_STATUS = 14
};

// Kích thước của các button và tổng số trạng thái của button đó
const int BUTTON_WIDTH = 179;
const int BUTTON_HEIGHT = 71;
const int TOTAL_BUTTONS = 4;

// Lớp LButton để quản lý các button lớn
class LButton
{
public:
    // Khởi tạo các biến nội bộ
    LButton();

    // Đặt vị trí của button
    void setPosition(int x, int y);

    // Xử lý sự kiện của chuột
    void handleEvent(SDL_Event *e);

    // Hiển thị button
    void render(SDL_Renderer *&gRenderer);

    // Tải texture cho button từ file
    bool loadFromFile(std::string path, SDL_Renderer *&gRenderer);

    // Giải phóng texture
    void freeB();

    // Lấy trạng thái hiện tại của button
    LButtonSprite getStatus();

    // Giải phóng trạng thái
    void freeStatus();

private:
    // Vị trí góc trên bên trái của button
    SDL_Point mPosition;

    // Trạng thái hiện tại của button
    LButtonSprite mCurrentSprite;

    // Các texture tương ứng với các trạng thái của button
    LTexture texture[BUTTON_SPRITE_TOTAL];
};

// Implementation

LButton::LButton() : mPosition{0, 0}, mCurrentSprite(BUTTON_SPRITE_MOUSE_OUT)
{
    // Khởi tạo các texture trống
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
    {
        texture[i] = LTexture();
    }
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent(SDL_Event *e)
{
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);

        bool inside = true;

        if (x < mPosition.x || x > mPosition.x + BUTTON_WIDTH || y < mPosition.y || y > mPosition.y + BUTTON_HEIGHT)
        {
            inside = false;
        }

        if (!inside)
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        else
        {
            switch (e->type)
            {
            case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

            case SDL_MOUSEBUTTONUP:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
}

void LButton::render(SDL_Renderer *&gRenderer)
{
    texture[mCurrentSprite].render(mPosition.x, mPosition.y, gRenderer);
    std::cout << "Rendering button at (" << mPosition.x << ", " << mPosition.y << ")" << std::endl;
}

bool LButton::loadFromFile(std::string path, SDL_Renderer *&gRenderer)
{
    // Tải texture cho mỗi trạng thái của button
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
    {
        std::string fullPath = path;
        if (!texture[i].loadFromFile(fullPath, gRenderer))
        {
            return false;
        }
    }
    return true;
}

void LButton::freeB()
{
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
    {
        texture[i].free();
    }
}

LButtonSprite LButton::getStatus()
{
    return mCurrentSprite;
}

void LButton::freeStatus()
{
    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

