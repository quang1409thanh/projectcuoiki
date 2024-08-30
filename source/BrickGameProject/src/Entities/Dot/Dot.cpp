//
// Created by Nguyễn Quang Thành on 8/28/2024.
//
#include "Dot.hpp"
Dot::Dot(Entity::ID id, Paddle& paddle)
    : Entity(id), dotComponent(0, 0, 0, 0), dotRenderComponent(0) {
    reset(paddle);
}

void Dot::handleEvent(SDL_Event& e, Paddle& paddle) {
    // Xử lý sự kiện của Dot
}

void Dot::move(float deltaTime, Brick brick[], int n, Paddle& paddle, int& count_Broken_Bricks, int& COUNT_DIES, bool& sfx, Mix_Chunk* ballcollision, Mix_Chunk* brickcollision) {
    // Xử lý di chuyển và va chạm
    dotComponent.shiftColliders();
}

void Dot::render(SDL_Renderer* renderer) {
    dotRenderComponent.render(renderer, dotComponent.getX(), dotComponent.getY());
}

void Dot::reset(Paddle& paddle) {
    // Đặt lại vị trí và trạng thái của Dot
}
