#include "Player.hpp"

Player::Player(vec2f scale)
{
    _scaleFactor = scale;
    sf::Texture *t = new sf::Texture();
    t->loadFromFile("./assets/img/Root_Walk.png");
    sf::IntRect rect({ 0, 128, 64, 64 });
    sf::Sprite *s = new sf::Sprite(*t);

    _pos = scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor);
    s->setPosition(_pos);
    s->setTextureRect(rect);
    s->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _drawable = s;
    _transformable = s;
}

Player::~Player()
{
}

void Player::update(float dt)
{
}
