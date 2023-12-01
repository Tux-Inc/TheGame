#include "Player.hpp"

Player::Player(vec2f scale)
{
    _scaleFactor = scale;
    sf::CircleShape *shape = new sf::CircleShape(_scaleFactor.x * 50);
    shape->setFillColor(sf::Color::Green);
    _pos = scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor);
    shape->setPosition(_pos);
    _drawables.push_back(shape);
}

Player::~Player()
{
}

void Player::update(float dt)
{
}
