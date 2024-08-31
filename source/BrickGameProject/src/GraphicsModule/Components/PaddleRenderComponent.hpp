//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef PADDLERENDERCOMPONENT_HPP
#define PADDLERENDERCOMPONENT_HPP
#include "../../CoreModule/ECS/Component.hpp"
#include "../LTexture.h"
#include "../GraphicsManager.hpp"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "BaseRenderComponent.hpp"
class PaddleRenderComponent : public BaseRenderComponent
{
public:
    PaddleRenderComponent() : BaseRenderComponent()
    {
        Logger::getInstance().log(INFO, "PaddleRenderComponent created.");
    }
    ~PaddleRenderComponent() override
    {
        Logger::getInstance().log(INFO, "PaddleRenderComponent destroyed.");
    }
protected:
    BaseLogicComponent* dynamic_castBaseLogicComponent() override
    {
        return dynamic_cast<PaddleLogicComponent*>(owner_->getLogicComponent().get());
    }

    std::string getComponentName() const override
    {
        return "PaddleRenderComponent";
    }
};


#endif // PADDLE_RENDER_COMPONENT_HPP
