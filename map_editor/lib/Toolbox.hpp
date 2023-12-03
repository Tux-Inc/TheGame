/*
** EPITECH PROJECT, 2023
** TheGame
** File description:
** Toolbox
*/

#ifndef TOOLBOX_HPP_
#define TOOLBOX_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <fstream>
#include <iostream>
#include <sstream>

class Tile {
    public:
        enum Type {
            FLOOR,
            WALL,
            OBJECT,
        };

        Tile(Type type, sf::Sprite *sprite, char tag = 'x')
        {
            _type = type;
            _sprite = sprite;
            _pos = sf::Vector2f(0, 0);
            _tag = tag;
        }

        Tile()
        {
            _type = Tile::Type::FLOOR;
            _sprite = new sf::Sprite();
            _pos = sf::Vector2f(0, 0);
            _tag = 'x';
        }

        ~Tile()
        {
            delete _sprite;
        }

        Type GetType() { return _type; }
        void SetType(Type type) { _type = type; }

        sf::Sprite *GetSprite() { return _sprite; }
        void SetSprite(sf::Sprite *sprite) { _sprite = sprite; }

        sf::Vector2f GetPosition() { return _pos; }
        void SetPosition(sf::Vector2f pos)
        {
            _pos = pos;
            _sprite->setPosition(pos);
        }

        char GetTag() { return _tag; }
        void SetTag(char tag) { _tag = tag; }

    protected:
    private:
        Type _type;
        sf::Sprite *_sprite;
        sf::Vector2f _pos;
        char _tag;
};

class Toolbox {

    public:
        Toolbox()
        {
            std::cout << "Toolbox constructor" << std::endl;
            _selectedTile = nullptr;

            _selectedTileRect = new sf::RectangleShape(sf::Vector2f(48, 48));
            _selectedTileRect->setFillColor(sf::Color::Transparent);
            _selectedTileRect->setOutlineThickness(2);
            _selectedTileRect->setOutlineColor(sf::Color::White);

            LoadSpritesheet("../assets/img/map_futuristique.png");
            LoadSprites("config.me");
            LoadFont("../assets/fonts/font.ttf");
        }

        ~Toolbox()
        {
            std::cout << "Toolbox destructor" << std::endl;
            for (auto tile : _tiles)
                delete tile;
        }

        void LoadSpritesheet(std::string filePath)
        {
            _spritesheet = new sf::Texture();
            if (!_spritesheet->loadFromFile(filePath))
                std::cerr << "Failed to load spritesheet" << std::endl;
        }

        void LoadSprites(std::string configFile)
        {
            size_t tileSize = 48;

            std::ifstream file(configFile);
            if (!file.is_open())
                std::cerr << "Failed to open config file" << std::endl;
            std::string line;
            std::vector<std::string> tokens;
            std::string delimiter = " ";
            std::string token;
            sf::Sprite *sprite;

            // Example line: "floor 0 0"
            // Example line: "wall 48 0"
            // Example line: "object 96 0"

            while (std::getline(file, line)) {
                std::stringstream ss(line);

                while (std::getline(ss, token, ' '))
                    tokens.push_back(token);

                sprite = new sf::Sprite;
                sprite->setTexture(*_spritesheet);
                sprite->setTextureRect(sf::IntRect(std::stoi(tokens[1]), std::stoi(tokens[2]), tileSize, tileSize));

                if (tokens[0] == "floor")
                    _tiles.push_back(new Tile(Tile::Type::FLOOR, sprite, tokens[3][0]));
                else if (tokens[0] == "wall")
                    _tiles.push_back(new Tile(Tile::Type::WALL, sprite, tokens[3][0]));
                else if (tokens[0] == "object")
                    _tiles.push_back(new Tile(Tile::Type::OBJECT, sprite, tokens[3][0]));
                else
                    std::cerr << "Invalid tile type" << std::endl;

                tokens.clear();
            }
        }

        void LoadFont(std::string filePath)
        {
            _font = new sf::Font();
            if (!_font->loadFromFile(filePath))
                std::cerr << "Failed to load font" << std::endl;
        }

        void CreateText(std::string text, sf::Vector2f position)
        {
            sf::Text *textObj = new sf::Text();
            textObj->setFont(*_font);
            textObj->setCharacterSize(24);
            textObj->setFillColor(sf::Color::White);
            textObj->setString(text);
            textObj->setPosition(position);
            _texts.push_back(textObj);
        }

        void Setup(sf::RenderWindow &window)
        {
            size_t tileSize = 48;
            float x = 0;
            float y = tileSize;

            // Setup walls
            CreateText("Walls", sf::Vector2f(0, 0 + tileSize / 2));

            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::WALL) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    x += tileSize;
                }
            }

            // Setup floors
            x = 0;
            y += tileSize * 2;

            CreateText("Floors", sf::Vector2f(0, y - tileSize / 2));

            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::FLOOR) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    x += tileSize;
                }
            }

            // Setup objects
            x = 0;
            y += tileSize * 2;

            CreateText("Objects", sf::Vector2f(0, y - tileSize / 2));

            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::OBJECT) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    x += tileSize;
                }
            }
        }

        void Draw(sf::RenderWindow &window)
        {
            for (auto tile : _tiles)
                window.draw(*tile->GetSprite());
            for (auto text : _texts)
                window.draw(*text);

            // Draw outlined selected tile
            if (_selectedTile != nullptr) {
                window.draw(*_selectedTileRect);
            }
        }

        Tile *GetSelectedTile() { return _selectedTile; }

        void UpdateSelectedTileOnClick(sf::RenderWindow &window)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePositionF(mousePosition.x, mousePosition.y);

            for (auto tile : _tiles) {
                if (tile->GetSprite()->getGlobalBounds().contains(mousePositionF)) {
                    _selectedTile = tile;
                    _selectedTileRect->setPosition(tile->GetSprite()->getPosition());
                }
            }
        }

        void SetSelectedTile(Tile *tile) { _selectedTile = tile; }

        unsigned int GetWindowWidth(sf::RenderWindow &window) { return window.getSize().x; }

    protected:
    private:
        sf::Texture *_spritesheet;
        std::vector<Tile *> _tiles;
        sf::Font *_font;
        std::vector<sf::Text *> _texts;
        Tile *_selectedTile;
        sf::RectangleShape *_selectedTileRect;
};

#endif /* !TOOLBOX_HPP_ */
