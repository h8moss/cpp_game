#pragma once
#include <vector>
#include <functional>

#include "entity.hpp"

class EntityManager
{
private:
    static EntityManager *instance;
    EntityManager();
    ~EntityManager();

    std::vector<Entity *> entities;

public:
    static EntityManager *getInstance();
    static void destroyInstance();

    std::vector<Entity *> getEntities();
    Entity *getEntity(std::string);
    void addEntity(Entity *);
    bool removeEntity(std::string);

    bool areColliding(Entity *, Entity *);
    Entity *getCollision(Entity *);
};