//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "Entity.hpp"

// Lớp cơ sở cho tất cả các hệ thống trong ECS
class System {
public:
    virtual ~System() = default;

    // Thực hiện các thao tác với các entity liên quan
    virtual void update(float deltaTime) = 0;

    // Thêm entity vào hệ thống
    void addEntity(const Entity& entity) {
        entities_.push_back(entity);
    }

protected:
    std::vector<Entity> entities_;  // Danh sách các entity mà hệ thống này quản lý
};

#endif //SYSTEM_HPP
