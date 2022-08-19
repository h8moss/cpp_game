#include "headings/entityManager.hpp"

#include "headings/physicsCube.hpp"
#include "headings/player.hpp"

EntityManager *EntityManager::instance{nullptr};

EntityManager::EntityManager(std::vector<Entity *> entities, Camera2D camera)
    : entities{entities}, camera{camera}
{
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

EntityManager *EntityManager::createInstance(std::vector<Entity *> entities, Camera2D camera)
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
    instance = new EntityManager(entities, camera);
    return instance;
}

EntityManager *EntityManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new EntityManager({}, {});
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