#include "headings/killable.hpp"

Killable::Killable(std::string id, Vector2 pos, Vector2 size) : Entity(id, pos, size) {}
Killable::~Killable() {}

void Killable::update()
{
    mainUpdate();

    if (health <= 0)
    {
        onDeath();
    }
}
void Killable::damage(int damage) { health -= damage; }
int Killable::getHealth() const { return health; }
