#include "headings/cameraController.hpp"

#include "headings/entityManager.hpp"
#include "headings/vectorOperations.hpp"
#include "headings/constants.hpp"

CameraController::CameraController(std::string id, Rectangle _cameraBounds)
    : Entity(id), cameraBounds{_cameraBounds}
{
}

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
        Vector2 cameraPosition{EntityManager::getInstance()->camera.target};
        cameraPosition = VectorOP::lerp(cameraPosition, player->getPosition(), 0.1f);

        Vector2 cameraSize{(float)Constants::SCREEN_WIDTH, (float)Constants::SCREEN_HEIGHT};

        cameraPosition = bindCameraLocation(cameraPosition, cameraSize);

        EntityManager::getInstance()->camera.target = cameraPosition;
    }
}

Vector2 CameraController::bindCameraLocation(Vector2 cameraLocation, Vector2 cameraSize)
{
    if (cameraBounds.height > 0 || cameraBounds.width > 0)
    {
        if (cameraLocation.x - cameraSize.x / 2 < cameraBounds.x)
        {
            cameraLocation.x = cameraBounds.x + cameraSize.x / 2;
        }
        else if (cameraLocation.x + cameraSize.x / 2 > cameraBounds.x + cameraBounds.width)
        {
            cameraLocation.x = cameraBounds.x + cameraBounds.width - cameraSize.x / 2;
        }
        if (cameraLocation.y - cameraSize.y / 2 < cameraBounds.y)
        {
            cameraLocation.y = cameraBounds.y + cameraSize.y / 2;
        }
        else if (cameraLocation.y + cameraSize.y / 2 > cameraBounds.y + cameraBounds.height)
        {
            cameraLocation.y = cameraBounds.y + cameraBounds.height - cameraSize.y / 2;
        }
    }

    return cameraLocation;
}

void CameraController::debugDraw() const
{
    DrawRectangleLines(cameraBounds.x + 5, cameraBounds.y + 5, cameraBounds.width - 10, cameraBounds.height - 10, GREEN);
}

void CameraController::draw() const
{
}