//
// Created by Nguyễn Quang Thành on 8/28/2024.
//
#include "GraphicsManager.hpp"
#include "SDL.h"

GraphicsManager& GraphicsManager::getInstance() {
    static GraphicsManager instance;
    return instance;
}

bool GraphicsManager::init(int screenWidth, int screenHeight) {
    gWindow = SDL_CreateWindow("Break Brick Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gRenderer) {
        return false;
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        return false;
    }

    return true;
}

SDL_Renderer* GraphicsManager::getRenderer() const {
    return gRenderer;
}

void GraphicsManager::cleanup() {
    if (gRenderer) {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = nullptr;
    }
    if (gWindow) {
        SDL_DestroyWindow(gWindow);
        gWindow = nullptr;
    }
    IMG_Quit();
}
