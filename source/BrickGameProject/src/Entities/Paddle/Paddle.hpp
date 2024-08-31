//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "../../CoreModule/ECS/Entity.hpp"
#include "PaddleComponent.hpp"
#include "../../GraphicsModule/Components/PaddleRenderComponent.hpp"
#include <vector>
#include <string>
#include "../../GraphicsModule/TextureManager.hpp"
// Lớp Paddle kế thừa từ Entity
class Paddle : public Entity
{
public:
    Paddle(Entity::ID id, int x, int y, const std::string &textureKey) : Entity(id)
    {
        Logger::getInstance().log(INFO, "Paddle created with ID: " + std::to_string(id));

        auto inputComp = std::make_shared<PaddleInputComponent>();
        auto logicComp = std::make_shared<PaddleLogicComponent>();
        auto renderComp = std::make_shared<PaddleRenderComponent>();

        // Lấy texture từ TextureManager
        auto texture = TextureManager::getInstance().getTexture(EntityType::PADDLE, textureKey);
        if (texture)
        {
            renderComp->setTexture(texture);
        }
        else
        {
            Logger::getInstance().log(WARNING, "Paddle texture not found: " + textureKey);
        }

        logicComp->setX(x);
        logicComp->setY(y);

        setInputComponent(inputComp);
        setLogicComponent(logicComp);
        setRenderComponent(renderComp);
    }

    ~Paddle() override
    {
        Logger::getInstance().log(INFO, "Paddle destroyed with ID: " + std::to_string(getID()));
    }
};

#endif // PADDLE_HPP
