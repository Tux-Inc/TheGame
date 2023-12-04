#include <P_button.hpp>

P_button::P_button(vec2f scale)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile("./assets/img/menu_sprites.png");

    _rect = sf::IntRect({ 200, 1050, 350, 150 });
    _sprite = new sf::Sprite(*_texture);

    _pos = scaleVector((sf::Vector2f) { ((float)sf::VideoMode::getDesktopMode().width - _rect.width) / 2, 200 }, _scaleFactor);
    _hitboxPos = scaleVector((sf::Vector2f) { 325, 300 }, _scaleFactor);

    _sprite->setPosition(_pos);
    _sprite->setTextureRect(_rect);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _hitbox = new sf::RectangleShape((sf::Vector2f) { 340, 150 });
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition((sf::Vector2f) {_pos.x + 10, _pos.y});
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _P_buttonId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
}

P_button::~P_button()
{
}

void P_button::update(float dt)
{
}

void P_button::setScene(int scene)
{
    *_currentScene = scene;
}

void P_button::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            setScene(GAME);
        }
    }
}
