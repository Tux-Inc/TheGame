#include <Enemy.hpp>

Enemy::Enemy()
{
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(100, 100));
    shape->setFillColor(sf::Color::Red);
    shape->setPosition(300, 300);
    _drawables.push_back(shape);
}

Enemy::~Enemy()
{

}

void Enemy::update(float dt)
{

}
