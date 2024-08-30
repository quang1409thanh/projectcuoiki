//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef BRICKCOMPONENT_HPP
#define BRICKCOMPONENT_HPP
#include <string>
#include "CoreModule/ECS/Component.hpp"

class BrickComponent : public LogicComponent {
public:
    BrickComponent(int x = 0, int y = 0, int velX = 0, int velY = 0)
        : mPosX(x), mPosY(y), mVelX(velX), mVelY(velY) {}

    void setPosition(int x, int y) { mPosX = x; mPosY = y; }
    int getX() const { return mPosX; }
    int getY() const { return mPosY; }
    int getVelX() const { return mVelX; }
    int getVelY() const { return mVelY; }

    void update(Entity &entity) override {
        mPosX += mVelX;
        mPosY += mVelY;
    }
private:
    int mPosX, mPosY;
    int mVelX, mVelY;
};

#endif //BRICKCOMPONENT_HPP

