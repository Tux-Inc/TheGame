#include <TileSprite.hpp>

TileSprite::TileSprite(vec2f scale, sf::Vector2f pos)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/map_futuristique.png");
    _direction = IDLE;

    _debug = false;
    _collides = true;

    _rect = sf::IntRect({ 0, 1198, 48, 48 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector(pos, _scaleFactor);
    _hitboxPos = scaleVector(pos, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x * (float)1.5, _scaleFactor.y * (float)1.5 });

    _hitbox = new sf::RectangleShape((sf::Vector2f) { 40, 43 });
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition(_hitboxPos);
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x * (float)1.5, _scaleFactor.y * (float)1.5 });
    _spriteId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
}

TileSprite::TileSprite(vec2f scale, sf::Vector2f pos, sf::Vector2f rescale, std::string texturePath, sf::IntRect rect)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile(texturePath);
    _direction = IDLE;

    _debug = false;
    _collides = true;

    _rect = rect;
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector(pos, _scaleFactor);
    _hitboxPos = scaleVector(pos, _scaleFactor);
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y * rescale.y });

    _hitbox = new sf::RectangleShape((sf::Vector2f) { static_cast<float>(_rect.width), static_cast<float>(_rect.height) });
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition(_hitboxPos);
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y * rescale.y });
    _spriteId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
}

TileSprite::~TileSprite()
{
}

void TileSprite::update(float dt)
{
}

void TileSprite::handleEvents(sf::Event event)
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
    }
}

void TileSprite::action(ActionType action, Direction direction)
{
}
