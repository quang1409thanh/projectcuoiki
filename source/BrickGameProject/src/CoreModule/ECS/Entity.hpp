//
// Created by Nguyễn Quang Thành on 8/28/2024.
//


#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <unordered_map>
#include <memory>
#include <SDL.h>
#include "Component.hpp"
#include "../../GraphicsModule/Logger.hpp"  // Thêm header Logger

// Entity base class
class Entity {
public:
    using ID = std::uint32_t;

    explicit Entity(ID id) : id_(id) {
        Logger::getInstance().log(INFO, "Entity created with ID: " + std::to_string(id_));
    }

    ID getID() const { return id_; }

    virtual void update() {
        if (logicComponent_) {
            logicComponent_->update();
        }
    }

    virtual void render(SDL_Renderer *&renderer) {
        if (renderComponent_) {
            renderComponent_->render(renderer);
        }
    }

    virtual void handleEvent(const SDL_Event& event) {
        if (inputComponent_) {
            inputComponent_->handleEvent(event);
        }
    }

    virtual ~Entity() {
        Logger::getInstance().log(INFO, "Entity destroyed with ID: " + std::to_string(id_));
    }

    void setLogicComponent(std::shared_ptr<LogicComponent> logicComponent) {
        logicComponent_ = std::move(logicComponent);
        logicComponent_->setOwner(this); // Đặt chủ sở hữu cho component
    }

    void setRenderComponent(std::shared_ptr<RenderComponent> renderComponent) {
        renderComponent_ = std::move(renderComponent);
        renderComponent_->setOwner(this); // Đặt chủ sở hữu cho component
    }

    void setInputComponent(std::shared_ptr<InputComponent> inputComponent) {
        inputComponent_ = std::move(inputComponent);
        inputComponent_->setOwner(this); // Đặt chủ sở hữu cho component
    }

    std::shared_ptr<LogicComponent> getLogicComponent() const {
        return logicComponent_;
    }

    std::shared_ptr<RenderComponent> getRenderComponent() const {
        return renderComponent_;
    }

    std::shared_ptr<InputComponent> getInputComponent() const {
        return inputComponent_;
    }
protected:
    ID id_;

    std::shared_ptr<LogicComponent> logicComponent_;
    std::shared_ptr<RenderComponent> renderComponent_;
    std::shared_ptr<InputComponent> inputComponent_;
};

// Entity manager to create and manage entities
class EntityManager {
public:
    EntityManager() : nextID_(0) {
        Logger::getInstance().log(INFO, "EntityManager created.");
    }

    template<typename T, typename... Args>
    std::shared_ptr<T> createEntity(Args&&... args) {
        Entity::ID newID = nextID_++;
        auto entity = std::make_shared<T>(newID, std::forward<Args>(args)...);
        entities_[newID] = entity;
        Logger::getInstance().log(INFO, "Entity created with ID: " + std::to_string(newID));
        return entity;
    }

    std::shared_ptr<Entity> getEntity(Entity::ID id) {
        auto it = entities_.find(id);
        if (it != entities_.end()) {
            return it->second;
        }
        return nullptr;
    }

    void removeEntity(Entity::ID id) {
        entities_.erase(id);
        Logger::getInstance().log(INFO, "Entity removed with ID: " + std::to_string(id));
    }

private:
    Entity::ID nextID_;  // Counter to generate unique IDs
    std::unordered_map<Entity::ID, std::shared_ptr<Entity>> entities_;  // Store entities
};

#endif // ENTITY_HPP
