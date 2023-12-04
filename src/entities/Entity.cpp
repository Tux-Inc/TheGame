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

Direction Entity::getDirection() const
{
    return _direction;
}

Direction Entity::getPreviousDirection() const
{
    return _prevDir;
}

Direction Entity::intersects(std::shared_ptr<IEntity> other)
{
    sf::FloatRect e1 = _hitbox->getGlobalBounds();
    sf::FloatRect e2 = other->getHitbox().getGlobalBounds();
    bool collides = e1.intersects(e2);
    if (!collides) {
        return IDLE;
    }

    sf::Vector2f obstaclePos = other->getHitboxPosition();
    Direction prevDirH = IDLE;
    Direction prevDirV = IDLE;
    if (_prevHitboxPos.x + _hitbox->getSize().x <= obstaclePos.x) {
        prevDirH = LEFT;
    } else if (_prevHitboxPos.x >= obstaclePos.x + other->getHitbox().getSize().x) {
        prevDirH = RIGHT;
    }
    if (_prevHitboxPos.y + _hitbox->getSize().y <= obstaclePos.y) {
        prevDirV = UP;
    } else if (_prevHitboxPos.y >= obstaclePos.y + other->getHitbox().getSize().y) {
        prevDirV = DOWN;
    }
    Direction dir = getDirection();
    Direction prevDir = getPreviousDirection();
    if (prevDir == RIGHT) {
        if (prevDirH == LEFT)
            return RIGHT;
        return LEFT;
    }
    if (prevDir == LEFT) {
        if (prevDirH == RIGHT)
            return LEFT;
        return RIGHT;
    }
    if (prevDir == UP) {
        if (prevDirV == DOWN)
            return UP;
        return DOWN;
    }
    if (prevDir == DOWN) {
        if (prevDirV == UP)
            return DOWN;
        return UP;
    }
    return IDLE;
}

sf::RectangleShape &Entity::getHitbox() const
{
    return *_hitbox;
}

sf::Vector2f Entity::getHitboxPosition() const
{
    return _hitboxPos;
}

sf::Vector2f Entity::getPrevHitboxPosition() const
{
    return _prevHitboxPos;
}

bool Entity::clicked() const
{
    return _clicked;
}
