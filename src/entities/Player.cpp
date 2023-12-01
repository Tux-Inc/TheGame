#include "Player.hpp"

Player::Player(vec2f scale)
{
    std::cout << "Player created" << std::endl;
    _scaleFactor = scale;
    sf::CircleShape* shape = new sf::CircleShape(_scaleFactor.x * 50);
    shape->setFillColor(sf::Color::Green);

    shape->setPosition(scaleVector((sf::Vector2f){100, 100}, _scaleFactor));
    _drawables.push_back(shape);
}

Player::~Player()
{
}

void Player::update(float dt)
{

}
