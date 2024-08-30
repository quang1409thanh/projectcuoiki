//
// Created by Nguyễn Quang Thành on 8/28/2024.
//
#include "Brick.hpp"
#include <iostream>
#include "string.h"
// Constructor của lớp Brick
Brick::Brick(Entity::ID id, int x, int y, int velX, int velY, BrickColor color)
    : Entity(id),
      brickComponent(x, y, velX, velY),
      brickRenderComponent(color) {}


#include <vector>
#include <memory>

// BrickManager class
class BrickManager {
public:
    // Add a new Brick to the manager
    void addBrick(std::shared_ptr<Brick> brick) {
        bricks_.push_back(std::move(brick));
    }

    // Update all bricks
    void updateAll() {
        for (auto& brick : bricks_) {
            brick->update();
        }
    }

    // Render all bricks
    void renderAll(SDL_Renderer* renderer) {
        for (auto& brick : bricks_) {
            brick->render(renderer);
        }
    }

    // Remove a brick by ID (example)
    void removeBrick(Entity::ID id) {
        bricks_.erase(std::remove_if(bricks_.begin(), bricks_.end(),
                                     [id](const std::shared_ptr<Brick>& brick) {
                                         return brick->getID() == id;
                                     }),
                      bricks_.end());
    }

private:
    std::vector<std::shared_ptr<Brick>> bricks_;  // Store bricks in a vector
};
