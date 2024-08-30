#include <SDL.h>
#include <iostream>
#include "GraphicsManager.hpp"
#include "TextureManager.hpp"
#include "../Entities/Paddle/Paddle.hpp"
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
    // Khởi tạo EntityManager
    EntityManager entityManager;

    // Tạo Paddle và các component liên quan
    auto paddle = entityManager.createEntity<Paddle>();

    cout << paddle.get()->getID() << endl;
    // Chạy vòng lặp chính
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        // Xử lý sự kiện
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            // Gửi sự kiện đến Paddle
            paddle->handleEvent(e);
        }

        // Cập nhật tất cả các thực thể
        paddle->update();

        // Xóa màn hình
        SDL_SetRenderDrawColor(gRenderer, 0xF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Render tất cả các thực thể
        paddle->render(gRenderer);
        // Hiển thị các thay đổi trên màn hình
        SDL_RenderPresent(gRenderer);
    }

    return 0;
}
