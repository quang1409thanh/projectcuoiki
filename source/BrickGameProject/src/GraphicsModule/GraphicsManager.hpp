//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP
#include <SDL.h>
#include <SDL_image.h>

class GraphicsManager {
public:
    static GraphicsManager& getInstance();

    bool init(int screenWidth, int screenHeight);
    SDL_Renderer* getRenderer() const;
    void cleanup();

private:
    GraphicsManager() = default;
    ~GraphicsManager() = default;
    GraphicsManager(const GraphicsManager&) = delete;
    GraphicsManager& operator=(const GraphicsManager&) = delete;

    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
};

#endif //GRAPHICSMANAGER_HPP
