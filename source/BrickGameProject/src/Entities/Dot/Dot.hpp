//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOT_HPP
#define DOT_HPP

#include "CoreModule/ECS/Entity.hpp"
#include "DotComponent.hpp"
#include "GraphicsModule/Components/DotRenderComponent.hpp"
#include "Entities/Paddle/Paddle.hpp"
#include "Entities/Brick/Brick.hpp"
#include <vector>
class Dot : public Entity
{
public:
    Dot(Entity::ID id, Paddle &paddle);

    void handleEvent(SDL_Event &e, Paddle &paddle);

    void Dot::move(float deltaTime, std::vector<Brick>& bricks, Paddle &paddle, int &count_Broken_Bricks, int &COUNT_DIES);
    void render(SDL_Renderer* renderer);
    void reset(Paddle& paddle);

    // Thêm các texture vào render component
    void addTexture(const std::string& key, const LTexture& texture) {
        dotRenderComponent.addTexture(key, texture);
    }

    // Đặt key của texture hiện tại để render
    void setCurrentTextureKey(const std::string& key) {
        dotRenderComponent.setCurrentTextureKey(key);
    }

private:
    DotComponent dotComponent;
    DotRenderComponent dotRenderComponent;
};

#endif // DOT_HPP
