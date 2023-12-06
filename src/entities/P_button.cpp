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
    _rotate = false;

    _clicked = false;
    sf::Vector2f buttonSize = (sf::Vector2f) { _sprite->getGlobalBounds().width, _sprite->getGlobalBounds().height };
    _pos = scaleVector((sf::Vector2f) { (float)(centerPos.x - (buttonSize.x / 2)), (float)(centerPos.y - (buttonSize.y / 2)) }, _scaleFactor);
    _hitboxPos = scaleVector((sf::Vector2f) { (float)(centerPos.x - (buttonSize.x / 2)), (float)(centerPos.y - (buttonSize.y / 2)) }, _scaleFactor);
    _font.loadFromFile("./assets/fonts/font.ttf");

    _sfText = new sf::Text();
    _sfText->setString(text);
    _sfText->setFont(_font);
    sf::Vector2f textPos = scaleVector((sf::Vector2f) { (float)(centerPos.x - _sprite->getGlobalBounds().width / 2), (float)(centerPos.y - _sfText->getGlobalBounds().height / 2) }, _scaleFactor);
    _sfText->setPosition(textPos);
    _sfText->setFillColor(sf::Color::White);
    _sfText->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });

    _sprite->setPosition(_pos);
    _sprite->setTexture(*_texture);
    _sprite->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _sprite->setOrigin((sf::Vector2f) { _sprite->getGlobalBounds().width / 2, _sprite->getGlobalBounds().height / 2 });

    _hitbox = new sf::RectangleShape(buttonSize);
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Green);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition((sf::Vector2f) { _hitboxPos.x, _hitboxPos.y });
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _hitbox->setOrigin((sf::Vector2f) { _hitbox->getGlobalBounds().width / 2, _hitbox->getGlobalBounds().height / 2 });

    _boxBorder = new sf::RectangleShape(buttonSize);
    _boxBorder->setFillColor(sf::Color::Transparent);
    _boxBorder->setOutlineColor(sf::Color::White);
    _boxBorder->setOutlineThickness(3);
    _boxBorder->setPosition((sf::Vector2f) { _hitboxPos.x, _hitboxPos.y });
    _boxBorder->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _boxBorder->setOrigin((sf::Vector2f) { _boxBorder->getGlobalBounds().width / 2, _boxBorder->getGlobalBounds().height / 2 });

    _P_buttonId = _drawables.size();
    _drawables.push_back(_sprite);
    _transformables.push_back(_sprite);
    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
    _textId = _drawables.size();
    _drawables.push_back(_sfText);
    _transformables.push_back(_sfText);
    _borderId = _drawables.size();
    _drawables.push_back(_boxBorder);
    _transformables.push_back(_boxBorder);
}

P_button::~P_button()
{
}

void P_button::update(float dt)
{
    for (size_t i = 0; i < _transformables.size(); i++) {
        if (_rotate) {
            _transformables[i]->setRotation(_transformables[i]->getRotation() + 1);
        } else {
            _transformables[i]->setRotation(0);
        }
    }
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
            _boxBorder->setOutlineColor(sf::Color::Cyan);
            _rotate = true;

        } else {
            _hover = false;
            _sfText->setFillColor(sf::Color::White);
            _boxBorder->setOutlineColor(sf::Color::White);
            _rotate = false;
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
