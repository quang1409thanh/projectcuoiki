//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOTRENDERCOMPONENT_HPP
#define DOTRENDERCOMPONENT_HPP
#include "../../CoreModule/ECS/Component.hpp"
#include <SDL.h>
#include "../LTexture.h"
#include <map>
#include <string>
#include "BaseRenderComponent.hpp"

class DotRenderComponent : public BaseRenderComponent
{
public:
    DotRenderComponent() : BaseRenderComponent()
    {
        Logger::getInstance().log(INFO, "DotRenderComponent created.");
    }
    ~DotRenderComponent() override
    {
        Logger::getInstance().log(INFO, "DotRenderComponent destroyed.");
    }
protected:
    BaseLogicComponent* dynamic_castBaseLogicComponent() override
    {
        return dynamic_cast<DotLogicComponent*>(owner_->getLogicComponent().get());
    }

    std::string getComponentName() const override
    {
        return "DotRenderComponent";
    }
};

#endif // DOT_RENDER_COMPONENT_HPP
