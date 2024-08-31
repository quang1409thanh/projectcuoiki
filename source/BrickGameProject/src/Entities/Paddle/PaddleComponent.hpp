//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef PADDLECOMPONENT_HPP
#define PADDLECOMPONENT_HPP
#include "../../CoreModule/ECS/Component.hpp"
#include "../../CoreModule/ECS/BaseLogicComponent.hpp"
// Component logic cụ thể cho Paddle
class PaddleLogicComponent : public BaseLogicComponent
{
public:
    PaddleLogicComponent(int x = 100, int y = 100, int velX = 0, int velY = 0)
        : BaseLogicComponent(x, y, velX, velY)
    {
        // Đã log trong BaseLogicComponent constructor
        Logger::getInstance().log(INFO, "PaddleLogicComponent created.");
    }

    ~PaddleLogicComponent() override
    {
        // Đã log trong BaseLogicComponent destructor
        Logger::getInstance().log(INFO, "PaddleLogicComponent destroyed.");
    }
    std::string getComponentName() const override { return "PaddleLogicComponent"; }

protected:

    void additionalUpdateLogic() override
    {
        // Kiểm tra giới hạn biên màn hình
        if (x_ < 0)
        {
            x_ = 0;
        }
        else if (x_ > SCREEN_WIDTH - PADDLE_WIDTH)
        {
            x_ = SCREEN_WIDTH - PADDLE_WIDTH;
        }
    }

private:
    static const int SCREEN_WIDTH = 400;
    static const int PADDLE_WIDTH = 90;
};

#endif // PADDLECOMPONENT_HPP

#ifndef PADDLE_INPUT_COMPONENT_HPP
#define PADDLE_INPUT_COMPONENT_HPP
const int PADDLE_VEL = 5;

// Component input cụ thể cho Paddle
class PaddleInputComponent : public InputComponent
{

public:
    void handleEvent(const SDL_Event &event) override
    {
        auto logicComponent = dynamic_cast<PaddleLogicComponent *>(owner_->getLogicComponent().get());
        if (!logicComponent)
        {
            Logger::getInstance().log(ERROR, "Failed to cast to PaddleLogicComponent.");
            return;
        }

        if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        {
            Logger::getInstance().log(DEBUG, "Handling SDL_KEYDOWN event for Paddle.");
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
            case SDLK_a:
                logicComponent->setVelX(logicComponent->getVelX() - PADDLE_VEL);
                Logger::getInstance().log(DEBUG, "Paddle moved left.");
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                logicComponent->setVelX(logicComponent->getVelX() + PADDLE_VEL);
                Logger::getInstance().log(DEBUG, "Paddle moved right.");
                break;
            }
        }
        else if (event.type == SDL_KEYUP && event.key.repeat == 0)
        {
            Logger::getInstance().log(DEBUG, "Handling SDL_KEYUP event for Paddle.");

            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
            case SDLK_a:
                logicComponent->setVelX(logicComponent->getVelX() + PADDLE_VEL);
                Logger::getInstance().log(DEBUG, "Paddle stopped moving left.");
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                logicComponent->setVelX(logicComponent->getVelX() - PADDLE_VEL);
                Logger::getInstance().log(DEBUG, "Paddle stopped moving right.");
                break;
            }
        }
    }

    ~PaddleInputComponent() override
    {
        Logger::getInstance().log(INFO, "PaddleInputComponent destroyed.");
    }
};

#endif // PADDLE_INPUT_COMPONENT_HPP
