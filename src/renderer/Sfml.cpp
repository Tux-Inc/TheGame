#include <Sfml.hpp>

Sfml::Sfml()
{
    _window.create(sf::VideoMode(800, 600), "SFML Entity Rendering");
}

Sfml::~Sfml()
{
}

void Sfml::init()
{
}

void Sfml::clear()
{
    _window.clear(sf::Color::Black);
}

void Sfml::draw(const sf::Drawable& drawable)
{
    _window.draw(drawable);
}

void Sfml::render()
{
    _window.display();
}

void Sfml::handleEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
        }
    }
}

bool Sfml::windowIsOpen() const
{
    return _window.isOpen();
}
