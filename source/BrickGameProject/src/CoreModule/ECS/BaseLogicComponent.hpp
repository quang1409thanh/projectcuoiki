#pragma once
// #include "../../GraphicsModule/Logger.hpp"
#include "Component.hpp"

class BaseLogicComponent : public LogicComponent
{
public:
    BaseLogicComponent(int x = 0, int y = 0, int velX = 0, int velY = 0)
        : x_(x), y_(y), velX_(velX), velY_(velY)
    {
        // Logger::getInstance().log(INFO, getComponentName() + " created.");
    }

    virtual ~BaseLogicComponent()
    {
        // Logger::getInstance().log(INFO, getComponentName() + " destroyed.");
    }

    void update() override
    {
        int prevX = x_;
        int prevY = y_;
        x_ += velX_;
        y_ += velY_;

        if (x_ != prevX || y_ != prevY)
        {
            Logger::getInstance().log(DEBUG, getComponentName() + " updated: Position (" + std::to_string(x_) + ", " + std::to_string(y_) + ")");
        }

        additionalUpdateLogic(); // Hàm ảo để lớp con thêm logic đặc biệt nếu cần
    }

    int getX() const { return x_; }
    int getY() const { return y_; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

    int getVelX() const { return velX_; }
    void setVelX(int velX) { velX_ = velX; }

    int getVelY() const { return velY_; }
    void setVelY(int velY) { velY_ = velY; }
    virtual std::string getComponentName() const = 0; // Lấy tên của component

protected:
    virtual void additionalUpdateLogic() {} // Hàm ảo để lớp con ghi đè thêm logic cập nhật

    int x_, y_;       // Vị trí
    int velX_, velY_; // Vận tốc
};
