/*
** File Name: Sfml.cpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Implementation of the Sfml class methods
**
** Copyright (c) 2023 Random Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the 'Software'), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
*/

#include <Sfml.hpp>
#include <iostream>

Sfml::Sfml()
{
    _w = sf::VideoMode::getDesktopMode().width;
    _h = sf::VideoMode::getDesktopMode().height;

    _scaleFactor = getScaleFactor();
    _window.create(sf::VideoMode(_w, _h), "TheGame");
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

void Sfml::handleEvents(EntityManager &manager)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
        }
        manager.handleEvents(_event);
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
