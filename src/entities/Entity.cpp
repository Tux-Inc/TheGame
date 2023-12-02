#include "Entity.hpp"

Entity::~Entity()
{
}

void Entity::draw(IRenderer &renderer)
{
    renderer.draw(*_drawable);
}

sf::Vector2f Entity::getPosition() const
{
    return _transformable->getPosition();
}

void Entity::setPosition(sf::Vector2f pos)
{
    _pos = pos;
    _transformable->setPosition(pos);
}
