//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef DOTCOMPONENT_HPP
#define DOTCOMPONENT_HPP

#include "CoreModule/ECS/Component.hpp"
  // Giả định rằng bạn có một lớp để định nghĩa cấu trúc Circle

struct Circle
{
	int x, y;
	int r;
};

class DotComponent : public LogicComponent {
public:
    DotComponent(int x = 0, int y = 0, int velX = 0, int velY = 0);

    void setPosition(int x, int y);
    void setVelocity(int velX, int velY);
    int getX() const;
    int getY() const;
    int getVelX() const;
    int getVelY() const;

    const Circle& getCollider() const;
    void shiftColliders();

    void update(Entity &entity) override{
        mPosX += mVelX;
        mCollider.x = mPosX;
        mPosY += mVelY;
        mCollider.y = mPosY;
    }
private:
    int mPosX, mPosY;
    int mVelX, mVelY;
    Circle mCollider;
};


#endif //DOTCOMPONENT_HPP
