#include <Sfml.hpp>
#include <iostream>

Sfml::Sfml()
{
    _w = sf::VideoMode::getDesktopMode().width / 2;
    _h = sf::VideoMode::getDesktopMode().height / 2;

    _scaleFactor = getScaleFactor();
    _window.create(sf::VideoMode(_w, _h), "TheGame");
    _window.setFramerateLimit(60);
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

void Sfml::draw(const sf::Drawable &drawable)
{
    _window.draw(drawable);
}

void Sfml::render()
{
    _window.display();
}

void Sfml::handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
        }
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }
        }
        scene->handleEvents(_event);
    }
}

bool Sfml::windowIsOpen() const
{
    return _window.isOpen();
}

vec2f Sfml::getScaleFactor() const
{
    vec2f scale;
    const float defaultWidth = 1920.0f;
    const float defaultHeight = 1080.0f;
    scale.x = static_cast<float>(_w) / defaultWidth;
    scale.y = static_cast<float>(_h) / defaultHeight;
    return scale;
}
