#include "TileMap.hpp"

TileMap::TileMap(vec2f scale)
{
    _scaleFactor = scale;
    _pos = scaleVector((sf::Vector2f) { 100, 100 }, _scaleFactor);
    _sprite = new sf::Sprite(_texture);
}

TileMap::TileMap(vec2f scale, const sf::Texture &t, const char c, vec2f pos)
{
    _scaleFactor = scale;
    _texture = t;
    _pos = scaleVector((sf::Vector2f) { pos.x, pos.y }, _scaleFactor);
    _sprite = new sf::Sprite(_texture);

    try {
        _rect = _rects.at(c);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        _rect = { 0, 0, 48, 48 };
    }
    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
}

TileMap::~TileMap()
{
}

void TileMap::update(float dt)
{
}

void TileMap::handleEvents(sf::Event event)
{
}
