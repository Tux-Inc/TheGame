#include "Player.hpp"

Player::Player(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/player.png");
    _dir = RIGHT;
    _offset = 0;
    _moving = false;

    _rect = sf::IntRect({ _offset, 128 * _dir, 128, 128 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _drawable = _sprite;
    _transformable = _sprite;
    _velocity.x = 0;
    _velocity.y = 0;
    _speed = 3;
}

Player::~Player()
{
}

void Player::update(float dt)
{
    updatePosition(dt);
}

void Player::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            _directions |= Up;
            _velocity.y = -1;
            _dir = UP;
            _moving = true;
        }
        if (event.key.code == sf::Keyboard::Down) {
            _directions |= Down;
            _velocity.y = 1;
            _dir = DOWN;
            _moving = true;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _directions |= Left;
            _dir = LEFT;
            _moving = true;

            _velocity.x = -1;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _directions |= Right;
            _dir = RIGHT;
            _moving = true;

            _velocity.x = 1;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            _velocity.y = 0;
            _velocity.x = 0;
            _directions &= ~Up;
            _moving = false;
        }
        if (event.key.code == sf::Keyboard::Down) {
            _directions &= ~Down;
            _velocity.y = 0;
            _velocity.x = 0;
            _moving = false;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _directions &= ~Left;
            _velocity.y = 0;
            _velocity.x = 0;
            _moving = false;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _directions &= ~Right;
            _velocity.y = 0;
            _velocity.x = 0;
            _moving = false;
        }
    }
}

void Player::updatePosition(float dt)
{
    sf::Vector2f pos = _transformable->getPosition();

    _rect.top = _dir * 128;

    _sprite->setTextureRect(_rect);
    if (dt > 1) {
        if (_moving) {
            if (_offset == 32) {
                _offset = 0;
            } else {
                _offset++;
            }
            _rect.left = (_offset / 4) * 128;
            _sprite->setTextureRect(_rect);
        }
        pos.x += _velocity.x * dt * _speed;
        pos.y += _velocity.y * dt * _speed;
        // if (_directions & Up) ()
        //     pos.y -= 100 * dt;
        // if (_directions & Down)
        //     pos.y += 100 * dt;
        // if (_directions & Left)
        //     pos.x -= 100 * dt;
        // if (_directions & Right)
        //     pos.x += 100 * dt;
        _transformable->setPosition(pos);
    }
}
