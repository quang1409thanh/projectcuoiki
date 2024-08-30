//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOTRENDERCOMPONENT_HPP
#define DOTRENDERCOMPONENT_HPP
#include "CoreModule/ECS/Component.hpp"
#include <SDL.h>
#include "GraphicsModule/LTexture.h"
#include <map>
#include <string>

class DotRenderComponent : public RenderComponent {
public:
    DotRenderComponent() {}

    // Thêm một texture với key cụ thể
    void addTexture(const std::string& key, const LTexture& texture) {
        textures_[key] = texture;
    }

    // Đặt key của texture hiện tại
    void setCurrentTextureKey(const std::string& key) {
        currentTextureKey_ = key;
    }

    // Render dot sử dụng texture hiện tại
    void render(SDL_Renderer *&renderer, int x, int y) {
        if (textures_.find(currentTextureKey_) != textures_.end()) {
            textures_[currentTextureKey_].render(x, y, renderer);
        }
    }

private:
    std::map<std::string, LTexture> textures_; // Lưu trữ các texture với key
    std::string currentTextureKey_; // Key của texture hiện tại
};

#endif //DOTRENDERCOMPONENT_HPP
