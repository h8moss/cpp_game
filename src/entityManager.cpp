#include "headings/entityManager.hpp"

#include "headings/physicsCube.hpp"
#include "headings/physicsFloor.hpp"
#include "headings/player.hpp"

EntityManager *EntityManager::instance{nullptr};

EntityManager::EntityManager()
{
    entities = {
        new PhysicsCube("cube1", 1, {180, 100}, {50, 50}),
        new PhysicsFloor("floor", 0, {0, 420}, {800, 50}),
        Player::getInstance(),
    };
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

bool removeEntity(std::string);