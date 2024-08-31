#pragma once
#include "../../CoreModule/ECS/Component.hpp"
#include "../GraphicsManager.hpp"
#include "../LTexture.h"
#include <map>
class BaseRenderComponent : public RenderComponent
{
public:
    BaseRenderComponent() : previousX_(0), previousY_(0)
    {
        // Logger::getInstance().log(INFO, getComponentName() + " created.");
    }

    virtual ~BaseRenderComponent()
    {
        // Logger::getInstance().log(INFO, getComponentName() + " destroyed.");
    }

    void setTexture(std::shared_ptr<LTexture> texture)
    {
        currentTexture_ = texture;
        if (texture)
        {
            Logger::getInstance().log(INFO, getComponentName() + " texture set.");
        }
        else
        {
            Logger::getInstance().log(WARNING, getComponentName() + " texture not set.");
        }
    }

    void render(SDL_Renderer *&renderer) override
    {
        if (auto logicComp = dynamic_castBaseLogicComponent())
        {
            int x = logicComp->getX();
            int y = logicComp->getY();

            if (currentTexture_)
            {
                currentTexture_->render(x, y, renderer);

                if (x != previousX_ || y != previousY_)
                {
                    Logger::getInstance().log(DEBUG, "Rendering " + getComponentName() + " texture at position (" + std::to_string(x) + ", " + std::to_string(y) + ")");
                    previousX_ = x;
                    previousY_ = y;
                }
            }
            else
            {
                Logger::getInstance().log(WARNING, getComponentName() + " texture is null.");
            }
        }
        else
        {
            Logger::getInstance().log(ERROR, "Failed to cast to " + getComponentName() + "LogicComponent.");
        }
    }

protected:
    virtual BaseLogicComponent *dynamic_castBaseLogicComponent() = 0; // Pure virtual method for casting logic component
    virtual std::string getComponentName() const = 0;                 // Pure virtual method for getting the component name

private:
    std::shared_ptr<LTexture> currentTexture_; // Texture hiện tại
    int previousX_;                            // Vị trí X trước đó
    int previousY_;                            // Vị trí Y trước đó
};
