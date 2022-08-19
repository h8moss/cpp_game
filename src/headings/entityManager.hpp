#pragma once
#include <vector>
#include <functional>

#include "entity.hpp"

class EntityManager
{
private:
    static EntityManager *instance;
    EntityManager(std::vector<Entity *> entities, Camera2D camera);
    ~EntityManager();

    std::vector<Entity *> entities;

public:
    Camera2D camera;

    static EntityManager *createInstance(std::vector<Entity *> entities, Camera2D camera);
    static EntityManager *getInstance();
    static void destroyInstance();

    std::vector<Entity *> getEntities();
    Entity *getEntity(std::string);
    void addEntity(Entity *);
    bool removeEntity(std::string);

    bool areColliding(Entity *, Entity *);
    Entity *getCollision(Entity *);
};