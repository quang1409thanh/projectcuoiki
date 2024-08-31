//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOTCOMPONENT_HPP
#define DOTCOMPONENT_HPP

#include "../../CoreModule/ECS/Entity.hpp"
#include "../../CoreModule/ECS/BaseLogicComponent.hpp"

struct Circle
{
	int x, y;
	int r;
};

#ifndef DOT_LOGIC_COMPONENT_HPP
#define DOT_LOGIC_COMPONENT_HPP

class DotLogicComponent : public BaseLogicComponent
{
public:
    DotLogicComponent() : BaseLogicComponent(100, 100, 0, 0)
    {
        // Đã log trong BaseLogicComponent constructor
        Logger::getInstance().log(INFO, "DotLogicComponent created.");
    }

    ~DotLogicComponent() override
    {
        // Đã log trong BaseLogicComponent destructor
        Logger::getInstance().log(INFO, "DotLogicComponent destroyed.");
    }
    std::string getComponentName() const override { return "DotLogicComponent"; }

protected:

    void additionalUpdateLogic() override
    {
        // Thêm logic đặc biệt cho Dot nếu cần
    }
};

#endif // DOT_LOGIC_COMPONENT_HPP



#ifndef DOT_INPUT_COMPONENT_HPP
#define DOT_INPUT_COMPONENT_HPP

class DotInputComponent : public InputComponent
{
public:
    void handleEvent(const SDL_Event &event) override
    {
        // Dot không cần xử lý sự kiện input nào
        // Logger::getInstance().log(DEBUG, "Dot does not handle any input events.");
    }

    ~DotInputComponent() override
    {
        Logger::getInstance().log(INFO, "DotInputComponent destroyed.");
    }
};

#endif // DOT_INPUT_COMPONENT_HPP


#endif //DOTCOMPONENT_HPP
