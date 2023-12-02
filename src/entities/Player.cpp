#include "Player.hpp"

Player::Player(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/player.png");
    _dir = RIGHT;

    _rect = sf::IntRect({ 0, 128 * _dir, 128, 128 });
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
        }
        if (event.key.code == sf::Keyboard::Down) {
            _directions |= Down;
            _velocity.y = 1;
            _dir = DOWN;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _directions |= Left;
            _dir = LEFT;

            _velocity.x = -1;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _directions |= Right;
            _dir = RIGHT;

            _velocity.x = 1;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            _velocity.y = 0;
            _velocity.x = 0;
            _directions &= ~Up;
        }
        if (event.key.code == sf::Keyboard::Down) {
            _directions &= ~Down;
            _velocity.y = 0;
            _velocity.x = 0;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _directions &= ~Left;
            _velocity.y = 0;
            _velocity.x = 0;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _directions &= ~Right;
            _velocity.y = 0;
            _velocity.x = 0;
        }
    }
}

void Player::updatePosition(float dt)
{
    sf::Vector2f pos = _transformable->getPosition();
    std::cout << _dir << std::endl;
    std::cout << _rect.top << std::endl;
    _rect.top = _dir * 128;
    std::cout << _rect.top << std::endl;

    _sprite->setTextureRect(_rect);
    if (dt > 1) {

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
