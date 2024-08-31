#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "TextureManager.hpp"
// Giả sử mỗi dòng trong file dữ liệu có định dạng: "EntityType X Y Color"
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "../CoreModule/ECS/Entity.hpp"
#include "../Entities/Brick/Brick.hpp"
#include "../Entities/Dot/Dot.hpp"
#include "../Entities/Paddle/Paddle.hpp"

std::vector<std::shared_ptr<Entity>> loadEntitiesFromFile(const std::string& filePath, EntityManager& entityManager)
{
    std::vector<std::shared_ptr<Entity>> entities;
    std::ifstream file(filePath);
    
    if (!file.is_open())
    {
        Logger::getInstance().log(ERROR, "Failed to open file: " + filePath);
        return entities;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string typeStr, textureKey;
        int x, y;

        if (!(iss >> typeStr >> x >> y >> textureKey)) {
            Logger::getInstance().log(WARNING, "Failed to parse line: " + line);
            continue; // Bỏ qua dòng không hợp lệ
        }

        std::shared_ptr<Entity> entity;

        if (typeStr == "PADDLE") {
            entity = entityManager.createEntity<Paddle>(x, y, textureKey);
        } else if (typeStr == "DOT") {
            entity = entityManager.createEntity<Dot>(x, y, textureKey);
        } else if (typeStr == "BRICK") {
            entity = entityManager.createEntity<Brick>(x, y, textureKey);
        } else {
            Logger::getInstance().log(ERROR, "Unknown entity type: " + typeStr);
            continue; // Loại không xác định, bỏ qua dòng này
        }

        if (entity)
        {
            entities.push_back(entity);
            Logger::getInstance().log(INFO, "Entity of type " + typeStr + " created with ID: " + std::to_string(entity->getID()));
        }
        else
        {
            Logger::getInstance().log(ERROR, "Failed to create entity of type " + typeStr);
        }
    }

    return entities;
}
// Example function to load textures into TextureManager
void loadAllTextures(SDL_Renderer* renderer)
{
    TextureManager& tm = TextureManager::getInstance();

    bool success = true;

    success &= tm.loadTexture(EntityType::BRICK, "BLUE", "D:/project/INT2215/projectcuoiki/source/Data/img/bricks/blue.png", renderer);
    success &= tm.loadTexture(EntityType::BRICK, "RED", "D:/project/INT2215/projectcuoiki/source/Data/img/bricks/red.png", renderer);
    success &= tm.loadTexture(EntityType::BRICK, "GREEN", "D:/project/INT2215/projectcuoiki/source/Data/img/bricks/green.png", renderer);
    // Load other colors for bricks
    success &= tm.loadTexture(EntityType::DOT, "DEFAULT", "D:/project/INT2215/projectcuoiki/source/Data/img/anim/ballanim.png", renderer);
    success &= tm.loadTexture(EntityType::PADDLE, "DEFAULT", "D:/project/INT2215/projectcuoiki/source/Data/img/paddle/paddlemedium.png", renderer);
    // Load other textures for paddles, dots, etc.

    if (success)
    {
        Logger::getInstance().log(INFO, "All textures loaded successfully.");
    }
    else
    {
        Logger::getInstance().log(ERROR, "Some textures failed to load.");
    }
}
