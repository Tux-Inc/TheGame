#include <Text.hpp>

Text::Text(vec2f scale, const std::string &text, sf::Vector2f centerPos, sf::Color color)
{
    _scaleFactor = scale;

    _direction = IDLE;
    _debug = false;
    _collides = true;
    _text = text;
    _hover = false;
    _startPos = centerPos;

    _clicked = false;
    _startPos = centerPos;
    _pos = scaleVector((sf::Vector2f) { (float)(centerPos.x), (float)(centerPos.y) }, _scaleFactor);
    _hitboxPos = scaleVector((sf::Vector2f) { (float)(centerPos.x), (float)(centerPos.y) }, _scaleFactor);
    _font.loadFromFile("./assets/fonts/font.ttf");

    _sfText = new sf::Text();
    _sfText->setString(text);
    _sfText->setFont(_font);
    sf::Vector2f textPos = scaleVector((sf::Vector2f) { (float)(centerPos.x), (float)(centerPos.y) }, _scaleFactor);

    sf::Vector2f textSize = (sf::Vector2f) { _sfText->getGlobalBounds().width, _sfText->getGlobalBounds().height };
    _sfText->setPosition(textPos);
    _sfText->setFillColor(color);
    _sfText->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _sfText->setOrigin((sf::Vector2f) { _sfText->getGlobalBounds().width / 2, _sfText->getGlobalBounds().height / 2 });

    _hitbox = new sf::RectangleShape(textSize);
    _hitbox->setFillColor(sf::Color::Transparent);
    _hitbox->setOutlineColor(sf::Color::Transparent);
    _hitbox->setOutlineThickness(1);
    _hitbox->setPosition((sf::Vector2f) { _hitboxPos.x, _hitboxPos.y });
    _hitbox->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
    _hitbox->setOrigin((sf::Vector2f) { _hitbox->getGlobalBounds().width / 2, _hitbox->getGlobalBounds().height / 2 });

    _hitboxId = _drawables.size();
    _drawables.push_back(_hitbox);
    _transformables.push_back(_hitbox);
    _textId = _drawables.size();
    _drawables.push_back(_sfText);
    _transformables.push_back(_sfText);
}

Text::~Text()
{
}

void Text::update(float dt)
{
}

void Text::setScene(int scene)
{
}

void Text::handleEvents(sf::Event event)
{
}

void Text::action(ActionType action, Direction direction)
{
}

void Text::reset()
{
    _clicked = false;
    _hover = false;
}
