#include "headings/entityManager.hpp"

#include "headings/physicsCube.hpp"
#include "headings/physicsFloor.hpp"
#include "headings/player.hpp"

EntityManager *EntityManager::instance{nullptr};

EntityManager::EntityManager()
{
    entities = {
        new PhysicsCube("cube1", {180, 100}, {50, 50}),
        new PhysicsCube("cube2", {250, 100}, {50, 50}),
        new PhysicsFloor("floor", {0, 420}, {800, 50}),
        new Player(),
    };
}

EntityManager::~EntityManager()
{
    for (int i{}; i < static_cast<int>(entities.size()); i++)
    {
        delete entities[i];
        entities[i] = nullptr;
    }

    entities = {};
}

EntityManager *EntityManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new EntityManager();
    }
    return instance;
}

std::vector<Entity *> EntityManager::getEntities() { return entities; }

Entity *EntityManager::getEntity(std::string id)
{
    for (auto e : entities)
    {
        if (e->getUniqueId() == id)
        {
            return e;
        }
    }
    return nullptr;
}

void EntityManager::addEntity(Entity *e)
{
    entities.push_back(e);
}

bool EntityManager::removeEntity(std::string id)
{
    for (auto it = entities.begin(); it != entities.end(); ++it)
    {
        if ((*it)->getUniqueId() == id)
        {
            entities.erase(it);
            return true;
        }
    }
    return false;
}

void EntityManager::destroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}