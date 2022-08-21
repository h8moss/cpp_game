#pragma once
#include "entity.hpp"

class Killable : public Entity
{
protected:
    int health;

    virtual void onDeath() = 0;

public:
    Killable(std::string id, Vector2 pos, Vector2 size);
    ~Killable();

    void update() override final;
    void damage(int damage);
    int getHealth() const;

    // Override this in child classes
    virtual void mainUpdate() = 0;
};