#include <Enemy.hpp>

Enemy::Enemy(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/enemy.png");
    _dir = RIGHT;

    _rect = sf::IntRect({ 0, 128 * _dir, 128, 128 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector((sf::Vector2f) { 300, 300 }, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _drawable = _sprite;
    _transformable = _sprite;
    _velocity.x = 0;
    _velocity.y = 0;
    _speed = 3;
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
}

void Enemy::handleEvents(sf::Event event)
{
}
