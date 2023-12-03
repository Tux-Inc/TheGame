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

class Layer {

    public:
        Layer(Tile::Type type, size_t width, size_t height)
        {
            _type = type;
            _width = width;
            _height = height;

            for (size_t y = 0; y < _height; y++) {
                std::vector<Tile *> row;
                for (size_t x = 0; x < _width; x++) {
                    row.push_back(new Tile(type, new sf::Sprite()));
                }
                _tiles.push_back(row);
            }
        }

        ~Layer()
        {
            for (auto row : _tiles) {
                for (auto tile : row) {
                    delete tile;
                }
            }
        }

        Tile *GetTile(size_t x, size_t y) { return _tiles[y][x]; }
        void SetTile(size_t x, size_t y, Tile *tile) { _tiles[y][x] = tile; }

        std::vector<std::vector<Tile *>> GetLayer() { return _tiles; }

        Tile::Type GetType() { return _type; }
        size_t GetWidth() { return _width; }
        size_t GetHeight() { return _height; }
        sf::Vector2f GetPosition() { return _pos; }

        void SetPosition(sf::Vector2f pos)
        {
            _pos = pos;
            for (size_t y = 0; y < _height; y++) {
                for (size_t x = 0; x < _width; x++) {
                    _tiles[y][x]->SetPosition(sf::Vector2f(pos.x + (x * 16), pos.y + (y * 16)));
                }
            }
        }

    protected:
    private:
        std::vector<std::vector<Tile *>> _tiles;
        Tile::Type _type;
        size_t _width;
        size_t _height;
        sf::Vector2f _pos;
};

class Map {
    public:
        Map(size_t width, size_t height)
        {
            _width = width;
            _height = height;
            _layers.push_back(new Layer(Tile::FLOOR, _width, _height));
            _layers.push_back(new Layer(Tile::WALL, _width, _height));
            _layers.push_back(new Layer(Tile::OBJECT, _width, _height));
            SetMapPosition(50, 50);
        }

        ~Map()
        {
            for (auto layer : _layers)
                delete layer;
        }

        void SetBackground(sf::Vector2f &pos)
        {
            _background = new sf::RectangleShape(sf::Vector2f(_width * 12, _height * 12));
            _background->setFillColor(sf::Color(30, 30, 30));
            _background->setPosition(pos);
        }

        void SetTile(size_t x, size_t y, Tile *tile, Tile::Type layerType)
        {
            for (auto layer : _layers) {
                if (layer->GetType() == layerType) {
                    layer->SetTile(x, y, tile);
                }
            }
        }

        void SetMapPosition(unsigned int x, unsigned int y)
        {
            sf::Vector2f pos(x, y);
            SetBackground(pos);
            for (auto layer : _layers) {
                layer->SetPosition(pos);
            }
        }

        void Draw(sf::RenderWindow &window)
        {
            window.draw(*_background);
            for (auto layer : _layers) {
                for (size_t y = 0; y < layer->GetHeight(); y++) {
                    for (size_t x = 0; x < layer->GetWidth(); x++) {
                        window.draw(*layer->GetTile(x, y)->GetSprite());
                    }
                }
            }
        }

    protected:
    private:
        std::vector<Layer *> _layers;
        size_t _width;
        size_t _height;
        sf::RectangleShape *_background;
};

class Editor {
    public:
        Editor()
        {
            sf::Vector2i mapWindowPosition(100, 200);

            SetupWindow(_mapWindow, sf::VideoMode(1280, 720), "Map Editor");
            SetupWindow(_toolWindow, sf::VideoMode(480, 720), "Toolbox");
            _mapWindow.setPosition(sf::Vector2i(mapWindowPosition.x, mapWindowPosition.y));
            mapWindowPosition = _mapWindow.getPosition();
            sf::Vector2u mapWindowSize = _mapWindow.getSize();
            _toolWindow.setPosition(sf::Vector2i(mapWindowSize.x + 100, mapWindowPosition.y + 23));

            _toolbox.Setup(_toolWindow);

            _map = new Map(90, 24);
            _map->SetMapPosition(0, 0);

            std::cout << "Map window position: " << mapWindowPosition.x << ", " << mapWindowPosition.y << std::endl;
            std::cout << "Tool window position: " << _toolWindow.getPosition().x << ", " << _toolWindow.getPosition().y << std::endl;
        }

        ~Editor()
        {
            delete _map;
        }

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
                if (_event.type == sf::Event::MouseButtonPressed) {
                    if (_event.mouseButton.button == sf::Mouse::Left) {
                        _toolbox.GetSelectedTileOnClick(window);
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
                _map->Draw(_mapWindow);

                Render(_mapWindow);
                Render(_toolWindow);
            }
        }

    protected:
    private:
        Toolbox _toolbox;
        Map *_map;
        sf::RenderWindow _mapWindow;
        sf::RenderWindow _toolWindow;
        sf::Event _event;
};

#endif /* !EDITOR_HPP_ */
