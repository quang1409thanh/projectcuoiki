//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include <map>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "LTexture.h" // Giả sử bạn có một lớp LTexture tương tự SDL_Texture

enum class EntityType { PADDLE, DOT, BRICK };

class TextureManager
{
public:
    // Singleton pattern to ensure only one instance of TextureManager exists
    static TextureManager& getInstance()
    {
        static TextureManager instance;
        return instance;
    }

    // Load texture for a specific entity type and texture key
    bool loadTexture(EntityType type, const std::string& key, const std::string& filePath, SDL_Renderer* renderer)
    {
        // Create a new LTexture object
        std::shared_ptr<LTexture> texture = std::make_shared<LTexture>();
        if (!texture->loadFromFile(filePath, renderer)) // Assuming LTexture has a loadFromFile method
        {
            return false;
        }

        textures[type][key] = texture;
        return true;
    }

    // Get texture for a specific entity type and texture key
    std::shared_ptr<LTexture> getTexture(EntityType type, const std::string& key) const
    {
        auto typeIt = textures.find(type);
        if (typeIt != textures.end())
        {
            auto keyIt = typeIt->second.find(key);
            if (keyIt != typeIt->second.end())
            {
                return keyIt->second;
            }
        }
        return nullptr;
    }

    // Free all loaded textures
    void freeTextures()
    {
        textures.clear(); // Shared pointers will automatically free the textures
    }

private:
    TextureManager() {}
    ~TextureManager() { freeTextures(); }

    std::map<EntityType, std::map<std::string, std::shared_ptr<LTexture>>> textures;
};

#endif //TEXTUREMANAGER_HPP
