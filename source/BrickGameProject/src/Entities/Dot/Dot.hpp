//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOT_HPP
#define DOT_HPP

#include "../../CoreModule/ECS/Entity.hpp"
#include "DotComponent.hpp"
#include "../../GraphicsModule/Components/DotRenderComponent.hpp"
#include "../../Entities/Paddle/Paddle.hpp"
#include <vector>
#include "../../GraphicsModule/TextureManager.hpp"
class Dot : public Entity
{
public:
    Dot(Entity::ID id, int x, int y, const std::string &textureKey) : Entity(id)
    {
        Logger::getInstance().log(INFO, "Dot created with ID: " + std::to_string(id));

        auto inputComp = std::make_shared<DotInputComponent>();
        auto logicComp = std::make_shared<DotLogicComponent>();
        auto renderComp = std::make_shared<DotRenderComponent>();

        // Lấy texture từ TextureManager
        auto texture = TextureManager::getInstance().getTexture(EntityType::DOT, textureKey);
        if (texture)
        {
            renderComp->setTexture(texture);
        }
        else
        {
            Logger::getInstance().log(WARNING, "Dot texture not found: " + textureKey);
        }

        logicComp->setX(x);
        logicComp->setY(y);

        setInputComponent(inputComp);
        setLogicComponent(logicComp);
        setRenderComponent(renderComp);
    }

    ~Dot() override
    {
        Logger::getInstance().log(INFO, "Dot destroyed with ID: " + std::to_string(getID()));
    }
};

#endif // DOT_HPP
