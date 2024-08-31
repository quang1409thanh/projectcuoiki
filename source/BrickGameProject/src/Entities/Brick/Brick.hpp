//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICK_HPP
#define BRICK_HPP

#include "../../CoreModule/ECS/Entity.hpp"
#include "BrickComponent.hpp"
#include "../../GraphicsModule/Components/BrickRenderComponent.hpp"
#include <vector>
#include "../../GraphicsModule/TextureManager.hpp"
class Brick : public Entity
{
public:
    Brick(Entity::ID id, int x, int y, const std::string &textureKey) : Entity(id)
    {
        Logger::getInstance().log(INFO, "Brick created with ID: " + std::to_string(id));

        auto inputComp = std::make_shared<BrickInputComponent>();
        auto logicComp = std::make_shared<BrickLogicComponent>();
        auto renderComp = std::make_shared<BrickRenderComponent>();

        // Lấy texture từ TextureManager
        auto texture = TextureManager::getInstance().getTexture(EntityType::BRICK, textureKey);
        if (texture)
        {
            renderComp->setTexture(texture);
        }
        else
        {
            Logger::getInstance().log(WARNING, "Brick texture not found: " + textureKey);
        }

        logicComp->setX(x);
        logicComp->setY(y);

        setInputComponent(inputComp);
        setLogicComponent(logicComp);
        setRenderComponent(renderComp);
    }

    ~Brick() override
    {
        Logger::getInstance().log(INFO, "Brick destroyed with ID: " + std::to_string(getID()));
    }
};
#endif // BRICK_HPP
