/*
** EPITECH PROJECT, 2023
** TheGame
** File description:
** Toolbox
*/

#ifndef TOOLBOX_HPP_
#define TOOLBOX_HPP_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

class Tile {
    public:
        enum class Type {
            FLOOR,
            WALL,
            OBJECT,
        };

        Tile(Type type, sf::Sprite *sprite)
        {
            _type = type;
            _sprite = sprite;
        }

        ~Tile()
        {
            std::cout << "Tile destructor" << std::endl;
            delete _sprite;
        }

        Type GetType() { return _type; }

        sf::Sprite *GetSprite() { return _sprite; }

    protected:
    private:
        Type _type;
        sf::Sprite *_sprite;
};

class Toolbox {

    public:
        Toolbox()
        {
            std::cout << "Toolbox constructor" << std::endl;
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
                    _tiles.push_back(new Tile(Tile::Type::FLOOR, sprite));
                else if (tokens[0] == "wall")
                    _tiles.push_back(new Tile(Tile::Type::WALL, sprite));
                else if (tokens[0] == "object")
                    _tiles.push_back(new Tile(Tile::Type::OBJECT, sprite));
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
            _text = new sf::Text();
            _text->setFont(*_font);
            _text->setCharacterSize(24);
            _text->setFillColor(sf::Color::White);
        }

        void Draw(sf::RenderWindow &window)
        {
            size_t tileSize = 48;
            float x = 0;
            float y = tileSize;

            // Draw walls
            _text->setString("Walls");
            _text->setPosition(0, 0 + tileSize / 2);
            window.draw(*_text);
            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::WALL) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    window.draw(*tile->GetSprite());
                    x += tileSize;
                }
            }

            // Draw floors
            x = 0;
            y += tileSize * 2;
            _text->setString("Floors");
            _text->setPosition(0, y - tileSize / 2);
            window.draw(*_text);
            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::FLOOR) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        std::cout << "x: " << x << std::endl;
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    window.draw(*tile->GetSprite());
                    x += tileSize;
                }
            }

            // Draw objects
            x = 0;
            y += tileSize * 2;
            _text->setString("Objects");
            _text->setPosition(0, y - tileSize / 2);
            window.draw(*_text);
            for (auto tile : _tiles) {
                if (tile->GetType() == Tile::Type::OBJECT) {
                    if (x + tileSize >= GetWindowWidth(window)) {
                        x = 0;
                        y += tileSize;
                    }
                    tile->GetSprite()->setPosition(x, y);
                    window.draw(*tile->GetSprite());
                    x += tileSize;
                }
            }
        }

        unsigned int GetWindowWidth(sf::RenderWindow &window) { return window.getSize().x; }

    protected:
    private:
        sf::Texture *_spritesheet;
        std::vector<Tile *> _tiles;
        sf::Font *_font;
        sf::Text *_text;
};

#endif /* !TOOLBOX_HPP_ */
