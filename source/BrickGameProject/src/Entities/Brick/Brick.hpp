//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICK_HPP
#define BRICK_HPP

#include "CoreModule/ECS/Entity.hpp"
#include "BrickComponent.hpp"
#include "BrickRenderComponent.hpp"

class Brick : public Entity {
public:
    Brick(Entity::ID id, int x = 0, int y = 0, int velX = 0, int velY = 0, BrickColor color = BrickColor::RED);

private:
    BrickComponent brickComponent;
    BrickRenderComponent brickRenderComponent;
};


#endif // BRICK_HPP
