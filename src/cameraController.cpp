#include "headings/cameraController.hpp"

#include "headings/entityManager.hpp"
#include "headings/vectorOperations.hpp"

CameraController::CameraController(std::string id) : Entity(id) {}
CameraController::~CameraController()
{
    player = nullptr;
}

void CameraController::setup()
{
    player = static_cast<Player *>(EntityManager::getInstance()->getEntity(Player::playerID));
}

void CameraController::update()
{
    if (player != nullptr)
    {
        Vector2 cameraPosition = EntityManager::getInstance()->camera.target;
        cameraPosition = VectorOP::lerp(cameraPosition, player->getPosition(), 0.1f);
        EntityManager::getInstance()->camera.target = cameraPosition;
    }
}

void CameraController::draw() const {}