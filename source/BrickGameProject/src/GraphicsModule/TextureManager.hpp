//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include <map>
class TextureManager {
public:
    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    }

    bool load(std::string id, std::string fileName, SDL_Renderer* renderer) {
        LTexture texture;
        if (!texture.loadFromFile(fileName, renderer)) {
            return false;
        }
        textureMap[id] = texture;
        return true;
    }

    void render(std::string id, int x, int y, SDL_Renderer* renderer) {
        textureMap[id].render(x, y, renderer);
    }

    void clear() {
        for (auto& texturePair : textureMap) {
            texturePair.second.free();
        }
        textureMap.clear();
    }

    LTexture& getTexture(std::string id) {
        return textureMap[id];
    }

private:
    TextureManager() {}
    std::map<std::string, LTexture> textureMap;
};

#endif //TEXTUREMANAGER_HPP
