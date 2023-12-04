#include <P_button.hpp>

P_button::P_button(vec2f scale, const std::string &text, sf::Vector2f centerPos, const std::string &texturePath)
{
    _scaleFactor = scale;
    _texture = new sf::Texture();
    _texture->loadFromFile(texturePath);
    _direction = IDLE;
    _debug = false;
    _collides = true;
    _text = text;
    _hover = false;
    _rect = sf::IntRect({ 200, 1050, 350, 150 });
    _sprite = new sf::Sprite(*_texture);

    _clicked = false;
    sf::Vector2f buttonSize = (sf::Vector2f) { _sprite->getGlobalBounds().width, _sprite->getGlobalBounds().height };
    _pos = scaleVector((sf::Vector2f) { (float)(centerPos.x - (buttonSize.x / 2)), (float)(centerPos.y - (buttonSize.y / 2)) }, _scaleFactor);
    _hitboxPos = scaleVector((sf::Vector2f) { (float)(centerPos.x - (buttonSize.x / 2)), (float)(centerPos.y - (buttonSize.y / 2)) }, _scaleFactor);
    _font.loadFromFile("./assets/fonts/font.ttf");
    _sfText = new sf::Text();
    _sfText->setFont(_font);
    _sfText->setFillColor(sf::Color::White);
    _sfText->setString(text);
    sf::Vector2f textPos = scaleVector((sf::Vector2f) { (float)(centerPos.x - (_sfText->getGlobalBounds().width / 2)), (float)(centerPos.y - (_sfText->getGlobalBounds().height / 2)) }, _scaleFactor);
    _sfText->setPosition(textPos);
    _sfText->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _sprite->setPosition(_pos);
    _sprite->setTexture(*_texture);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _hitbox = new sf::RectangleShape(buttonSize);
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition((sf::Vector2f) { _hitboxPos.x, _hitboxPos.y });
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _P_buttonId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
    _textId = _drawables.size();
    _drawables.push_back(_sfText);
    _transformables.push_back(_sfText);
}

P_button::~P_button()
{
}

void P_button::update(float dt)
{
}

void P_button::setScene(int scene)
{
}

void P_button::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::MouseMoved) {

        if (_hitbox->getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
            _hover = true;
            _sfText->setFillColor(sf::Color::Cyan);
        } else {
            _hover = false;
            _sfText->setFillColor(sf::Color::White);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (_hitbox->getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _clicked = true;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (_hitbox->getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _clicked = false;
            }
        }
    }
}

void P_button::action(ActionType action, Direction direction)
{
}