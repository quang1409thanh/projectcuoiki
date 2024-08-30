//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "../../CoreModule/ECS/Entity.hpp"
#include "PaddleComponent.hpp"
#include "../../GraphicsModule/Components/PaddleRenderComponent.hpp"
#include <vector>
#include <string>
// Lớp Paddle kế thừa từ Entity
class Paddle : public Entity
{
public:
    Paddle(Entity::ID id) : Entity(id) {
    Logger::getInstance().log(INFO, "Paddle created with ID: " + std::to_string(id));

    // Khởi tạo các component cụ thể cho Paddle
    auto inputComp = std::make_shared<PaddleInputComponent>();
    auto logicComp = std::make_shared<PaddleLogicComponent>();
    auto renderComp = std::make_shared<PaddleRenderComponent>();

    // Khởi tạo các texture
    std::vector<std::pair<std::string, std::string>> textureFiles = {
        {"small", "D:/project/INT2215/projectcuoiki/source/Data/img/paddle/paddlesmall.png"},
        {"medium", "D:/project/INT2215/projectcuoiki/source/Data/img/paddle/paddlemedium.png"},
        {"large", "D:/project/INT2215/projectcuoiki/source/Data/img/paddle/paddlelarge.png"}
    };

    // Gọi phương thức khởi tạo textures
    renderComp->initTextures(textureFiles);
    renderComp->setCurrentTextureKey("medium");

    // Đặt các component cho thực thể
    setInputComponent(inputComp);
    setLogicComponent(logicComp);
    setRenderComponent(renderComp);
}

    ~Paddle() override
    {
        Logger::getInstance().log(INFO, "Paddle destroyed with ID: " + std::to_string(getID()));
    }
};

#endif // PADDLE_HPP
