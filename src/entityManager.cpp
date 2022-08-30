#include "headings/entityManager.hpp"

#include "headings/physicsCube.hpp"
#include "headings/player.hpp"
#include "headings/physicalWall.hpp"
#include "headings/vectorOperations.hpp"

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

void EntityManager::createWalls(Vector2 size, int offset, int hiddenOffset)
{
    Vector2 TLCorner{VectorOP::multiply(size, -0.5)};

    Vector2 posL{VectorOP::add(TLCorner, {static_cast<float>(hiddenOffset) * -1, 0})};
    Vector2 posR{VectorOP::add(TLCorner, {size.x - offset, 0})};
    Vector2 posT{VectorOP::add(TLCorner, {0, static_cast<float>(hiddenOffset) * -1})};
    Vector2 posD{VectorOP::add(TLCorner, {0, size.y - offset})};

    Vector2 sizeV{static_cast<float>(offset) + hiddenOffset, size.y};
    Vector2 sizeH{size.x, static_cast<float>(offset) + hiddenOffset};

    PhysicalWall *wallLeft = new PhysicalWall("WALL L", posL, sizeV);
    PhysicalWall *wallRight = new PhysicalWall("WALL R", posR, sizeV);
    PhysicalWall *wallTop = new PhysicalWall("WALL T", posT, sizeH);
    PhysicalWall *wallDown = new PhysicalWall("WALL D", posD, sizeH);

    addEntity(wallLeft);
    addEntity(wallRight);
    addEntity(wallTop);
    addEntity(wallDown);
}