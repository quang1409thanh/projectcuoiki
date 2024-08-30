//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include "CoreModule/ECS/System.hpp"
#include "Entities/Brick/BrickComponent.hpp"
#include "Components/BrickRenderComponent.hpp"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

    SDL_Window* window_;
    SDL_Renderer* renderer_;

    // // Các hệ thống
    // RenderSystem renderSystem_;

    // // Các component và entity
    // std::unordered_map<Entity, BrickRenderComponent> brickRenderComponents_;
    // std::unordered_map<Entity, PositionComponent> positionComponents_;
    std::vector<Entity> entities_;
};

#endif // GAME_HPP
