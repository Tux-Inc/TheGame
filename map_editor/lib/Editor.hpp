/*
** EPITECH PROJECT, 2023
** TheGame
** File description:
** Editor
*/

#ifndef EDITOR_HPP_
#define EDITOR_HPP_

#include <cstdio>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Toolbox.hpp"

class Editor {
    public:
        enum class TileType {
            FLOOR,
            WALL,
            SPAWN,
            EXIT,
        };

        Editor()
        {
            sf::Vector2i mapWindowPosition(100, 200);

            SetupWindow(_mapWindow, sf::VideoMode(1280, 720), "Map Editor");
            SetupWindow(_toolWindow, sf::VideoMode(480, 720), "Toolbox");
            _mapWindow.setPosition(sf::Vector2i(mapWindowPosition.x, mapWindowPosition.y));
            mapWindowPosition = _mapWindow.getPosition();
            sf::Vector2u mapWindowSize = _mapWindow.getSize();
            _toolWindow.setPosition(sf::Vector2i(mapWindowSize.x + 100, mapWindowPosition.y + 23));

            std::cout << "Map window position: " << mapWindowPosition.x << ", " << mapWindowPosition.y << std::endl;
            std::cout << "Tool window position: " << _toolWindow.getPosition().x << ", " << _toolWindow.getPosition().y << std::endl;
        }

        ~Editor() { }

        void SetupWindow(sf::RenderWindow &window, sf::VideoMode mode, std::string title, sf::Uint32 style = sf::Style::Default)
        {
            window.create(mode, title, style);
            window.setFramerateLimit(60);
        }

        void Render(sf::RenderWindow &window) { window.display(); }

        void ClearWindow(sf::RenderWindow &window, sf::Color color = sf::Color::Black) { window.clear(color); }

        void HandleEvents(sf::RenderWindow &window)
        {
            while (window.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _mapWindow.close();
                    _toolWindow.close();
                }
                if (_event.type == sf::Event::KeyPressed) {
                    if (_event.key.code == sf::Keyboard::Escape) {
                        _mapWindow.close();
                        _toolWindow.close();
                    }
                }
            }
        }

        void Run()
        {
            while (_mapWindow.isOpen()) {
                HandleEvents(_mapWindow);
                HandleEvents(_toolWindow);

                ClearWindow(_mapWindow, sf::Color(21, 21, 21));
                ClearWindow(_toolWindow, sf::Color(21, 21, 21));

                _toolbox.Draw(_toolWindow);

                Render(_mapWindow);
                Render(_toolWindow);
            }
        }

    protected:
    private:
        Toolbox _toolbox;
        sf::RenderWindow _mapWindow;
        sf::RenderWindow _toolWindow;
        sf::Event _event;
};

#endif /* !EDITOR_HPP_ */
