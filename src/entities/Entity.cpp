#include "Entity.hpp"

Entity::~Entity()
{
}

void Entity::draw(IRenderer &renderer)
{
    for (size_t i = 0; i < _drawables.size(); i++) {
        renderer.draw(*_drawables[i]);
    }
}

sf::Vector2f Entity::getPosition(size_t assetId) const
{
    return _transformables[assetId]->getPosition();
}

void Entity::setPosition(sf::Vector2f pos, size_t assetId)
{
    _pos = pos;
    _transformables[assetId]->setPosition(pos);
}
