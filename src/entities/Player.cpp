#include "Player.hpp"

Player::Player(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/player.png");
    _dir = RIGHT;
    _dirs = std::vector<bool>(4, false);
    _dirs[_dir - 8] = true;
    _debug = false;

    _offset = 0;
    _moving = false;

    _rect = sf::IntRect({ _offset, 128 * _dir, 128, 128 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor);
    _hitboxPos = scaleVector((sf::Vector2f) { 125, 125 }, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });

    _hitbox = new sf::RectangleShape((sf::Vector2f) { 78, 103 });
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition(_hitboxPos);
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _spriteId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
    _velocity.x = 0;
    _velocity.y = 0;
    _speed = 1.5 * _scaleFactor.x;
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
        if (event.key.code == sf::Keyboard::P) {
            _debug = !_debug;
            if (_debug) {
                ((sf::RectangleShape *)_transformables[_hitboxId])->setOutlineColor(sf::Color::Green);
            } else {
                ((sf::RectangleShape *)_transformables[_hitboxId])->setOutlineColor(sf::Color::Transparent);
            }
        }
        if (event.key.code == sf::Keyboard::Up) {
            if (!_dirs[2]) {
                _velocity.y = -1;
                _dir = UP;
                _dirs[0] = true;
                _moving = true;
            }
        }
        if (event.key.code == sf::Keyboard::Down) {
            if (!_dirs[0]) {
                _velocity.y = 1;
                _dir = DOWN;
                _dirs[2] = true;
                _moving = true;
            }
        }
        if (event.key.code == sf::Keyboard::Left) {
            if (!_dirs[3]) {
                _dir = LEFT;
                _moving = true;
                _dirs[1] = true;
                _velocity.x = -1;
            }
        }
        if (event.key.code == sf::Keyboard::Right) {
            if (!_dirs[1]) {
                _dir = RIGHT;
                _moving = true;
                _dirs[3] = true;
                _velocity.x = 1;
            }
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            _velocity.y = 0;
            _directions &= ~Up;
            _dirs[0] = false;
        }
        if (event.key.code == sf::Keyboard::Down) {
            _directions &= ~Down;
            _velocity.y = 0;
            _dirs[2] = false;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _directions &= ~Left;
            _velocity.x = 0;
            _dirs[1] = false;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _directions &= ~Right;
            _velocity.x = 0;
            _dirs[3] = false;
        }
        size_t i = 0;
        for (; i < _dirs.size(); i++) {
            if (_dirs[i]) {
                break;
            }
        }
        if (i == 4) {
            _moving = false;
        }
    }
}

void Player::updatePosition(float dt)
{
    _pos = _transformables[_spriteId]->getPosition();
    _hitboxPos = _transformables[_hitboxId]->getPosition();

    for (size_t i = 0; i < _dirs.size(); i++) {
        if (_dirs[i]) {
            _rect.top = (i + 8) * 128;
            break;
        }
    }

    _sprite->setTextureRect(_rect);
    if (dt > 1 && _moving) {

        if (_offset == 32) {
            _offset = 0;
        } else {
            _offset++;
        }
        _rect.left = (_offset / 4) * 128;
        _sprite->setTextureRect(_rect);
        _pos.x += _velocity.x * dt * _speed;
        _pos.y += _velocity.y * dt * _speed;
        _hitboxPos.x += _velocity.x * dt * _speed;
        _hitboxPos.y += _velocity.y * dt * _speed;
        setPosition(_pos, _spriteId);
        setPosition(_hitboxPos, _hitboxId);
    }
}
