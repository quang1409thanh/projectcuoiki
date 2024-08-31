#include <SDL.h>
#include <iostream>
#include "GraphicsManager.hpp"
#include "TextureManager.hpp"
#include "../Entities/Paddle/Paddle.hpp"
#include "../Entities/Dot/Dot.hpp"
#include "../Entities/Brick/Brick.hpp"
#include "utils.hpp"
using namespace std;
// Screen dimension constants
const int SCREEN_WIDTH = 400;

const int SCREEN_HEIGHT = 600;

// khoảng cách bên trái đến khung trò chơi
const int SCREEN_LEFT = 20;

// khoảng cách bên phải đến khung trò chơi
const int SCREEN_RIGHT = 20;

// khoảng cách bên trên đến khung trò chơi
const int SCREEN_TOP = 60;

// khoảng cách bên dưới đến khung trò chơi
const int SCREEN_BOTTOM = 70;
int main(int argc, char *args[])
{
    // Khởi tạo hệ thống đồ họa
    if (!GraphicsManager::getInstance().init(SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        std::cerr << "Failed to initialize graphics!" << std::endl;
        return -1;
    }

    SDL_Renderer *gRenderer = GraphicsManager::getInstance().getRenderer();

    // Tải tất cả textures vào TextureManager
    loadAllTextures(gRenderer);

    // Khởi tạo EntityManager
    EntityManager entityManager;

    // Load entities từ file
    auto entities = loadEntitiesFromFile("D:/project/INT2215/projectcuoiki/source/BrickGameProject/src/GraphicsModule/entities.txt", entityManager);

    // Main game loop
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            for (auto& entity : entities)
            {
                entity->handleEvent(e);
            }
        }

        for (auto& entity : entities)
        {
            entity->update();
        }

        SDL_SetRenderDrawColor(gRenderer, 0xF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        for (auto& entity : entities)
        {
            entity->render(gRenderer);
        }

        SDL_RenderPresent(gRenderer);
    }

    return 0;
}
