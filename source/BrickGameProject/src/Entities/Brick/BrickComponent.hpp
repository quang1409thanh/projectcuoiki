//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICKCOMPONENT_HPP
#define BRICKCOMPONENT_HPP
#include <string>
#include "../../CoreModule/ECS/Component.hpp"
#include "../../CoreModule/ECS/BaseLogicComponent.hpp"
// Component input cụ thể cho Brick (nếu cần, có thể bỏ qua nếu Brick không có input)
class BrickInputComponent : public InputComponent
{
public:
    void handleEvent(const SDL_Event &event) override
    {
        // Brick có thể không cần xử lý sự kiện, nhưng nếu cần, bạn có thể thêm logic ở đây.
        // Logger::getInstance().log(INFO, "BrickInputComponent handling event.");
    }

    ~BrickInputComponent() override
    {
        Logger::getInstance().log(INFO, "BrickInputComponent destroyed.");
    }
};

#endif // BRICK_INPUT_COMPONENT_HPP

#ifndef BRICK_LOGIC_COMPONENT_HPP
#define BRICK_LOGIC_COMPONENT_HPP

class BrickLogicComponent : public BaseLogicComponent
{
public:
    BrickLogicComponent(int x = 0, int y = 0, int velX = 0, int velY = 0, int health = 100)
        : BaseLogicComponent(x, y, velX, velY), health_(health)
    {
        // Không cần thiết phải log lại vì đã log trong BaseLogicComponent constructor
        Logger::getInstance().log(INFO, "BrickLogicComponent created with health: " + std::to_string(health_));
    }

    ~BrickLogicComponent() override
    {
        // Không cần thiết phải log lại vì đã log trong BaseLogicComponent destructor
        Logger::getInstance().log(INFO, "BrickLogicComponent destroyed.");
    }

    void takeDamage(int damage)
    {
        health_ -= damage;
        Logger::getInstance().log(INFO, "Brick took damage. Current health: " + std::to_string(health_));
        if (health_ <= 0)
        {
            Logger::getInstance().log(INFO, "Brick health depleted. Marking for destruction.");
            // Thêm logic xử lý khi Brick bị phá hủy
        }
    }

    int getHealth() const { return health_; }
    void setHealth(int health) { health_ = health; }
    std::string getComponentName() const override { return "BrickLogicComponent"; }

protected:

    void additionalUpdateLogic() override
    {
        if (health_ <= 0)
        {
            Logger::getInstance().log(INFO, "Brick health depleted. Marking for destruction.");
            // Thêm logic xử lý khi brick bị phá hủy
        }
    }

private:
    int health_; // Sức khỏe của brick
};

#endif // BRICK_LOGIC_COMPONENT_HPP
