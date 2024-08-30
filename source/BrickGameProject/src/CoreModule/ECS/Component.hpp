//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

// Component.hpp

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"  // Đảm bảo Entity được định nghĩa trước khi sử dụng trong Component
#include <SDL.h>       // Thư viện SDL cho các sự kiện và renderer

class Entity; // Forward declaration

// Lớp cơ sở Component
class Component {
public:
    virtual ~Component() = default;

    // Thiết lập con trỏ ngược đến thực thể cha
    void setOwner(Entity* owner) { owner_ = owner; }

protected:
    Entity* owner_ = nullptr;  // Con trỏ ngược đến thực thể cha
};

// Interface cho LogicComponent
class LogicComponent : public Component {
public:
    virtual void update() = 0; // Phương thức trừu tượng phải được override
    virtual ~LogicComponent() = default;
};

// Interface cho RenderComponent
class RenderComponent : public Component {
public:
    virtual void render(SDL_Renderer *&renderer) = 0; // Phương thức trừu tượng phải được override
    virtual ~RenderComponent() = default;
};

// Interface cho InputComponent
class InputComponent : public Component {
public:
    virtual void handleEvent(const SDL_Event& event) = 0; // Phương thức trừu tượng phải được override
    virtual ~InputComponent() = default;
};

#endif // COMPONENT_HPP
