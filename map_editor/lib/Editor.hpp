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
        Layer()
        {
            _type = Tile::Type::FLOOR;
            _width = 0;
            _height = 0;
            _tiles = nullptr;
        }

        Layer(Tile::Type type, size_t width, size_t height)
        {
            _type = type;
            _width = width;
            _height = height;
            _tiles = new Tile *[_width];
            for (size_t i = 0; i < _width; i++) {
                _tiles[i] = new Tile[_height];
            }

            // Give default tiles to the layer
            for (size_t y = 0; y < _height; y++) {
                for (size_t x = 0; x < _width; x++) {
                    _tiles[x][y].SetType(_type);
                }
            }
        }

        ~Layer()
        {
            for (size_t i = 0; i < _width; i++) {
                delete[] _tiles[i];
            }
            delete[] _tiles;
        }

        Tile **GetTiles() { return _tiles; }
        void SetTiles(Tile **tiles) { _tiles = tiles; }

        Tile *GetTile(size_t x, size_t y) { return &_tiles[x][y]; }
        void SetTile(size_t x, size_t y, Tile *tile) { _tiles[x][y] = *tile; }

        Tile::Type GetType() { return _type; }
        void SetType(Tile::Type type) { _type = type; }

        size_t GetWidth() { return _width; }
        void SetWidth(size_t width) { _width = width; }

        size_t GetHeight() { return _height; }
        void SetHeight(size_t height) { _height = height; }

    protected:
    private:
        Tile **_tiles;
        Tile::Type _type;
        size_t _width;
        size_t _height;
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

            // Give default tiles to the map
        }

        ~Map()
        {
            for (auto layer : _layers)
                delete layer;
        }

        void SetTile(size_t x, size_t y, Tile *tile)
        {
            for (auto layer : _layers) {
                if (layer->GetType() == tile->GetType()) {
                    layer->SetTile(x, y, tile);
                }
            }
        }

        void Draw(sf::RenderWindow &window)
        {
            size_t draw_x = 0;
            size_t draw_y = 0;
            size_t tileSize = 48;
            size_t window_w = window.getSize().x;

            for (auto layer : _layers) {
                for (size_t y = 0; y < layer->GetHeight(); y++) {
                    for (size_t x = 0; x < layer->GetWidth(); x++) {
                        if (draw_x + tileSize >= window_w) {
                            draw_x = 0;
                            draw_y += tileSize;
                        }
                        layer->GetTile(x, y)->GetSprite()->setPosition(draw_x, draw_y);
                        window.draw(*layer->GetTile(x, y)->GetSprite());
                        draw_x += tileSize;
                    }
                }
                draw_x = 0;
                draw_y = 0;
            }
        }

    protected:
    private:
        std::vector<Layer *> _layers;
        size_t _width;
        size_t _height;
};

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

            _toolbox.Setup(_toolWindow);

            _map = new Map(90, 20);

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
