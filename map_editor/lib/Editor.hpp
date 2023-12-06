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
        Layer(Tile::Type type, size_t width, size_t height, std::string filePath)
        {
            _type = type;
            _width = width;
            _height = height;

            _tiles = FileToTiles(filePath, type);
            _texture.loadFromFile("../assets/img/map_futuristique.png");
            if (!_texture.loadFromFile("../assets/img/map_futuristique.png"))
                std::cout << "Error loading texture" << std::endl;
        }

        std::vector<std::vector<Tile *>> FileToTiles(std::string filePath, Tile::Type type)
        {
            std::vector<std::vector<Tile *>> tiles;
            std::ifstream file(filePath);

            if (file.is_open()) {
                std::string line;
                while (getline(file, line)) {
                    std::vector<Tile *> row;
                    for (char c : line) {
                        Tile *tile = new Tile(type, new sf::Sprite(), c);
                        tile->GetSprite()->setTexture(_texture, false);
                        tile->GetSprite()->setTextureRect(GetRectFromChar(c, type));
                        tile->GetSprite()->setScale(0.25f, 0.25f);
                        row.push_back(tile);
                    }
                    tiles.push_back(row);
                }
            }
            file.close();
            return tiles;
        }

        sf::IntRect GetRectFromChar(char c, Tile::Type type)
        {
            std::ifstream file("config.me");
            if (!file.is_open())
                std::cerr << "Failed to open config file" << std::endl;
            std::string line;

            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string line;
                std::vector<std::string> tokens;
                std::string delimiter = " ";
                std::string token;

                while (std::getline(ss, token, ' '))
                    tokens.push_back(token);

                if (tokens[0] == "floor" && tokens[3][0] == c && type == Tile::Type::FLOOR)
                    return sf::IntRect(std::stoi(tokens[1]), std::stoi(tokens[2]), 48, 48);
                if (tokens[0] == "wall" && tokens[3][0] == c && type == Tile::Type::WALL)
                    return sf::IntRect(std::stoi(tokens[1]), std::stoi(tokens[2]), 48, 48);
                if (tokens[0] == "object" && tokens[3][0] == c && type == Tile::Type::OBJECT)
                    return sf::IntRect(std::stoi(tokens[1]), std::stoi(tokens[2]), 48, 48);

                tokens.clear();
            }

            file.close();
            return sf::IntRect(48, 0, 48, 48);
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
            for (auto row : _tiles) {
                for (auto tile : row) {
                    tile->SetPosition(pos);
                    pos.x += 12;
                }
                pos.x = _pos.x;
                pos.y += 12;
            }
        }

    protected:
    private:
        std::vector<std::vector<Tile *>> _tiles;
        Tile::Type _type;
        size_t _width;
        size_t _height;
        sf::Vector2f _pos;
        sf::Texture _texture;
};

class Map {
    public:
        Map(size_t width, size_t height)
        {
            _width = width;
            _height = height;
            _layers.push_back(new Layer(Tile::Type::FLOOR, _width, _height, "../assets/maps/map1/layers1"));
            _layers.push_back(new Layer(Tile::Type::WALL, _width, _height, "../assets/maps/map1/layers2"));
            _layers.push_back(new Layer(Tile::Type::OBJECT, _width, _height, "../assets/maps/map1/layers3"));
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

        sf::Vector2f GetMapPosition()
        {
            return _layers[0]->GetPosition();
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

            // // Draw floor layer
            // for (size_t y = 0; y < _layers[Tile::Type::FLOOR]->GetHeight(); y++) {
            //     for (size_t x = 0; x < _layers[Tile::Type::FLOOR]->GetWidth(); x++) {
            //         window.draw(*_layers[Tile::Type::FLOOR]->GetTile(x, y)->GetSprite());
            //     }
            // }

            // // Draw object layer
            // for (size_t y = 0; y < _layers[Tile::Type::OBJECT]->GetHeight(); y++) {
            //     for (size_t x = 0; x < _layers[Tile::Type::OBJECT]->GetWidth(); x++) {
            //         window.draw(*_layers[Tile::Type::OBJECT]->GetTile(x, y)->GetSprite());
            //     }
            // }

            // // Draw wall layer
            // for (size_t y = 0; y < _layers[Tile::Type::WALL]->GetHeight(); y++) {
            //     for (size_t x = 0; x < _layers[Tile::Type::WALL]->GetWidth(); x++) {
            //         window.draw(*_layers[Tile::Type::WALL]->GetTile(x, y)->GetSprite());
            //     }
            // }
        }

        std::vector<Layer *> GetLayers() { return _layers; }

    protected:
    private:
        std::vector<Layer *> _layers;
        std::vector<std::string> _tags;
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

            _map = new Map(46, 24);

            // Center map in map window
            _map->SetMapPosition((_mapWindow.getSize().x / 2) - (_map->GetLayers()[0]->GetWidth() * 12 / 2), (_mapWindow.getSize().y / 2) - (_map->GetLayers()[0]->GetHeight() * 12 / 2));

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

        void CreateFile()
        {
            std::ofstream file("../assets/maps/map1/temp");
            if (!file.is_open())
                std::cerr << "Failed to open file" << std::endl;
            for (size_t y = 0; y < _map->GetLayers()[Tile::Type::WALL]->GetHeight(); y++) {
                for (size_t x = 0; x < _map->GetLayers()[Tile::Type::WALL]->GetWidth(); x++) {
                    file << _map->GetLayers()[Tile::Type::WALL]->GetTile(x, y)->GetTag();
                }
                file << std::endl;
            }

            file.close();
        }

        void SaveToFile()
        {
            std::ofstream file("../assets/maps/map1/layers1");
            if (!file.is_open())
                std::cerr << "Failed to open file" << std::endl;

            for (size_t y = 0; y < _map->GetLayers()[Tile::Type::FLOOR]->GetHeight(); y++) {
                for (size_t x = 0; x < _map->GetLayers()[Tile::Type::FLOOR]->GetWidth(); x++) {
                    file << _map->GetLayers()[Tile::Type::FLOOR]->GetTile(x, y)->GetTag();
                }
                file << std::endl;
            }

            file.close();

            file.open("../assets/maps/map1/layers2");
            if (!file.is_open())
                std::cerr << "Failed to open file" << std::endl;

            for (size_t y = 0; y < _map->GetLayers()[Tile::Type::WALL]->GetHeight(); y++) {
                for (size_t x = 0; x < _map->GetLayers()[Tile::Type::WALL]->GetWidth(); x++) {
                    file << _map->GetLayers()[Tile::Type::WALL]->GetTile(x, y)->GetTag();
                }
                file << std::endl;
            }

            file.close();

            file.open("../assets/maps/map1/layers3");
            if (!file.is_open())
                std::cerr << "Failed to open file" << std::endl;

            for (size_t y = 0; y < _map->GetLayers()[Tile::Type::OBJECT]->GetHeight(); y++) {
                for (size_t x = 0; x < _map->GetLayers()[Tile::Type::OBJECT]->GetWidth(); x++) {
                    file << _map->GetLayers()[Tile::Type::OBJECT]->GetTile(x, y)->GetTag();
                }
                file << std::endl;
            }
            file.close();
        }

        void HandleEvents(sf::RenderWindow &window)
        {
            while (window.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _mapWindow.close();
                    _toolWindow.close();
                    // CreateFile();
                    SaveToFile();
                }
                if (_event.type == sf::Event::KeyPressed) {
                    if (_event.key.code == sf::Keyboard::Escape) {
                        _mapWindow.close();
                        _toolWindow.close();
                        // CreateFile();
                        SaveToFile();
                    }
                }
                if (_event.type == sf::Event::MouseButtonPressed) {
                    if (_event.mouseButton.button == sf::Mouse::Left) {
                        if (_toolWindow.hasFocus()) {
                            _toolbox.UpdateSelectedTileOnClick(window);
                        }
                    }
                    if (_event.mouseButton.button == sf::Mouse::Left) {
                        if (_mapWindow.hasFocus()) {
                            ReplaceTileWithToolboxTile(window);
                        }
                    }
                }
            }
        }

        void ReplaceTileWithToolboxTile(sf::RenderWindow &window)
        {
            // Check if toolbox has a selected tile
            if (_toolbox.GetSelectedTile() == nullptr)
                return;

            // Get mouse position relative to map
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mapPos = _map->GetMapPosition();
            sf::Vector2f tilePos = sf::Vector2f(mousePos.x - mapPos.x, mousePos.y - mapPos.y);
            size_t tileSize = 12;
            size_t x = tilePos.x / tileSize;
            size_t y = tilePos.y / tileSize;
            Tile *tile = _toolbox.GetSelectedTile();
            std::cout << "Replacing tile at " << x << ", " << y << std::endl;

            // Check if clicking out of bounds
            if (x >= _map->GetLayers()[0]->GetWidth() || y >= _map->GetLayers()[0]->GetHeight())
                return;

            // Replace tile
            _map->GetLayers()[tile->GetType()]->GetTile(x, y)->GetSprite()->setTextureRect(tile->GetSprite()->getTextureRect());
            _map->GetLayers()[tile->GetType()]->GetTile(x, y)->SetTag(tile->GetTag());
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
