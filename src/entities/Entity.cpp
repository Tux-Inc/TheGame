#include "Entity.hpp"

Entity::~Entity()
{
    for (const auto& drawable : _drawables) {
            delete drawable;
    }
}

void Entity::draw(IRenderer& renderer)
{
    for (size_t i = 0; i < _drawables.size(); i++) {
        renderer.draw(*_drawables[i]);
    }   
}