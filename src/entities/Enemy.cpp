#include <Enemy.hpp>

Enemy::Enemy(vec2f scale)
{
    _scaleFactor = scale;

    sf::RectangleShape *shape = new sf::RectangleShape(scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor));
    shape->setFillColor(sf::Color::Red);
    _pos = scaleVector((sf::Vector2f) { 300, 300 }, _scaleFactor);
    shape->setPosition(_pos);
    _drawables.push_back(shape);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
}
