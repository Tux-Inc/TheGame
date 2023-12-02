#include <Enemy.hpp>

Enemy::Enemy(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/enemy.png");
    _dir = RIGHT;

    _offset = 0;
    _moving = true;

    _rect = sf::IntRect({ _offset, 128 * _dir, 128, 128 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector((sf::Vector2f) { 300, 300 }, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _spriteId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _velocity.x = 1;
    _velocity.y = 0;
    _speed = 1.5 * _scaleFactor.x;
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
    sf::Vector2f pos = _transformables[_spriteId]->getPosition();

    if (dt > 1 && _moving) {

        if (_offset == 32) {
            _offset = 0;
        } else {
            _offset++;
        }
        _rect.left = (_offset / 4) * 128;
        _sprite->setTextureRect(_rect);
        sf::Vector2f tmp = scaleVector((sf::Vector2f) { 1920, 1080 }, _scaleFactor);
        if (pos.x > tmp.x) {
            pos.x = scaleVector((sf::Vector2f) { -100, 0 }, _scaleFactor).x;
        } else {
            pos.x += _velocity.x * dt * _speed;
        }
        _transformables[_spriteId]->setPosition(pos);
    }
}

void Enemy::handleEvents(sf::Event event)
{
}
