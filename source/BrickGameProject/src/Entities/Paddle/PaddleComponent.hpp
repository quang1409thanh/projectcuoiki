//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef PADDLECOMPONENT_HPP
#define PADDLECOMPONENT_HPP
#include "../../CoreModule/ECS/Component.hpp"

// Component logic cụ thể cho Paddle
class PaddleLogicComponent : public LogicComponent
{
public:
    PaddleLogicComponent(int x = 100, int y = 100, int velX = 0, int velY = 0)
        : x_(x), y_(y), velX_(velX), velY_(velY)
    {
        Logger::getInstance().log(INFO, "PaddleLogicComponent created.");
    }

    void update() override
    {
        // Cập nhật vị trí của paddle dựa vào vận tốc
        int prevX_ = x_;
        int prevY_ = y_;
        x_ += velX_;
        y_ += velY_;
        // Kiểm tra giới hạn biên màn hình
        if (x_ < 0)
        {
            x_ = 0;
        }
        else if (x_ > SCREEN_WIDTH - PADDLE_WIDTH)
        {
            x_ = SCREEN_WIDTH - PADDLE_WIDTH;
        }

        // Ghi log chỉ khi có sự thay đổi trong vị trí
        if (x_ != prevX_ || y_ != prevY_)
        {
            Logger::getInstance().log(DEBUG, "Paddle updated: Position (" + std::to_string(x_) + ", " + std::to_string(y_) + ")");
        }

        // Có thể thêm logic xử lý giới hạn di chuyển của paddle ở đây
    }

    void setVelX(int velX) { velX_ = velX; }
    int getVelX() const { return velX_; }

    void setVelY(int velY) { velY_ = velY; }
    int getVelY() const { return velY_; }

    int getX() const { return x_; }
    int getY() const { return y_; }

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

    ~PaddleLogicComponent() override
    {
        Logger::getInstance().log(INFO, "PaddleLogicComponent destroyed.");
    }

private:
    int x_, y_;       // Vị trí của paddle
    int velX_, velY_; // Vận tốc của paddle
    // Screen dimension constants
    const int SCREEN_WIDTH = 400;

    const int SCREEN_HEIGHT = 600;
	static const int PADDLE_WIDTH = 90;
	static const int PADDLE_HEIGHT = 20;

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
