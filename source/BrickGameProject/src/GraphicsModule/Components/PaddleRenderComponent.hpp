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
class PaddleRenderComponent : public RenderComponent
{
public:
    PaddleRenderComponent()
        : previousX_(0), previousY_(0), positionChanged_(true) // Khởi tạo giá trị mặc định
    {
        Logger::getInstance().log(INFO, "PaddleRenderComponent created.");
    }

    ~PaddleRenderComponent()
    {
        Logger::getInstance().log(INFO, "PaddleRenderComponent destroyed.");
    }

    // Thêm một texture với key cụ thể
    void addTexture(const std::string &key, std::shared_ptr<LTexture> texture)
    {
        textures_[key] = texture;
    }

    // Đặt key của texture hiện tại
    void setCurrentTextureKey(const std::string &key)
    {
        // Kiểm tra xem key có tồn tại trong textures_ không
        if (textures_.find(key) != textures_.end())
        {
            currentTextureKey_ = key;
            Logger::getInstance().log(INFO, "Current texture key set to: " + key);
        }
        else
        {
            // Thông báo lỗi nếu key không tồn tại
            Logger::getInstance().log(ERROR, "Texture key '" + key + "' not found in textures.");
        }
    }

    // Render paddle sử dụng texture hiện tại
    void render(SDL_Renderer *&renderer) override
    {
        // Lấy vị trí từ component logic
        if (auto logicComp = dynamic_cast<PaddleLogicComponent *>(owner_->getLogicComponent().get()))
        {
            int x = logicComp->getX();
            int y = logicComp->getY();

            // Render texture nếu tồn tại
            auto it = textures_.find(currentTextureKey_);
            if (it != textures_.end() && it->second)
            {
                it->second->render(x, y, renderer);
                // Kiểm tra sự thay đổi vị trí
                if (x != previousX_ || y != previousY_)
                {
                    Logger::getInstance().log(DEBUG, "Rendering texture: " + currentTextureKey_ + " at position (" + std::to_string(x) + ", " + std::to_string(y) + ")");

                    // Cập nhật vị trí trước đó
                    previousX_ = x;
                    previousY_ = y;
                }
            }
            else
            {
                Logger::getInstance().log(WARNING, "Texture with key " + currentTextureKey_ + " not found or texture is null.");
            }
        }
        else
        {
            Logger::getInstance().log(ERROR, "Failed to cast to PaddleLogicComponent.");
        }
    }

    // Hàm khởi tạo textures từ danh sách file
    void initTextures(const std::vector<std::pair<std::string, std::string>> &textureFiles)
    {
        for (const auto &[key, file] : textureFiles)
        {
            auto texture = std::make_shared<LTexture>();
            SDL_Renderer *renderer = GraphicsManager::getInstance().getRenderer();
            if (texture->loadFromFile(file, renderer))
            {
                addTexture(key, texture);
                Logger::getInstance().log(INFO, "Texture " + key + " loaded from " + file);
            }
            else
            {
                Logger::getInstance().log(ERROR, "Failed to load texture from " + file);
            }
        }
    }

private:
    std::map<std::string, std::shared_ptr<LTexture>> textures_; // Lưu trữ các texture với con trỏ thông minh
    std::string currentTextureKey_;                             // Key của texture hiện tại
    int previousX_;                                             // Vị trí X trước đó
    int previousY_;                                             // Vị trí Y trước đó
    bool positionChanged_;                                      // Cờ để kiểm tra sự thay đổi vị trí
};

#endif // PADDLE_RENDER_COMPONENT_HPP
