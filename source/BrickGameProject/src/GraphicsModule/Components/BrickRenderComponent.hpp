//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICKRENDERCOMPONENT_HPP
#define BRICKRENDERCOMPONENT_HPP
#include "CoreModule/ECS/Component.hpp"
#include "GraphicsModule/TextureManager.hpp"

enum class BrickColor
{
    RED,
    BLUE,
    GREEN,
    DARK_GREEN,
    INDIGO,
    ORANGE,
    PINK,
    SOLID,
    VIOLET,
    YELLOW
};

class BrickRenderComponent : public RenderComponent
{
public:
    BrickRenderComponent(BrickColor color = BrickColor::RED)
        : color_(color) {}

    void render(SDL_Renderer *&renderer, int x, int y)
    {
        TextureManager::getInstance().render(BrickColorToString(color_), x, y, renderer);
    }

    BrickColor getColor() const { return color_; }
    void setColor(BrickColor color) { color_ = color; }

private:
    BrickColor color_;

    std::string BrickColorToString(BrickColor color)
    {
        // Map BrickColor enum to a string identifier for the texture
        // Implementation depends on your TextureManager
        switch (color)
        {
        case BrickColor::BLUE:
            return "BLUE";
        case BrickColor::RED:
            return "RED";
        case BrickColor::GREEN:
            return "GREEN";
        case BrickColor::DARK_GREEN:
            return "DARK_GREEN";
        case BrickColor::INDIGO:
            return "INDIGO";
        case BrickColor::ORANGE:
            return "ORANGE";
        case BrickColor::PINK:
            return "PINK";
        case BrickColor::SOLID:
            return "SOLID";
        case BrickColor::VIOLET:
            return "VIOLET";
        case BrickColor::YELLOW:
            return "YELLOW";
        default:
            return "";
        }
    }
};

#endif // BRICKRENDERCOMPONENT_HPP
