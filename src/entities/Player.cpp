#include "Player.hpp"

Player::Player()
{
    std::cout << "Player created" << std::endl;
    sf::CircleShape* shape = new sf::CircleShape(50);
    shape->setFillColor(sf::Color::Green);
    shape->setPosition(100, 100);
    _drawables.push_back(shape);
}

Player::~Player()
{
}

void Player::update(float dt)
{

}
