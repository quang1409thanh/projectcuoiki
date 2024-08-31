//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICKRENDERCOMPONENT_HPP
#define BRICKRENDERCOMPONENT_HPP
#include "../../CoreModule/ECS/Component.hpp"
#include "../GraphicsManager.hpp"
#include "../LTexture.h"
#include <map>
#include "BaseRenderComponent.hpp"

// Các lớp kế thừa từ BaseRenderComponent
class BrickRenderComponent : public BaseRenderComponent
{
public:
    BrickRenderComponent() : BaseRenderComponent()
    {
        Logger::getInstance().log(INFO, "BrickRenderComponent created.");
    }
    ~BrickRenderComponent() override
    {
        Logger::getInstance().log(INFO, "BrickRenderComponent destroyed.");
    }
protected:
    BaseLogicComponent* dynamic_castBaseLogicComponent() override
    {
        return dynamic_cast<BrickLogicComponent*>(owner_->getLogicComponent().get());
    }

    std::string getComponentName() const override
    {
        return "BrickRenderComponent";
    }
};

#endif // BRICKRENDERCOMPONENT_HPP
