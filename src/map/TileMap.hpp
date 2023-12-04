#ifndef TILEMAP_HPP
    #define TILEMAP_HPP

    #include <vector>
    #include <fstream>
    #include <struct.h>
    #include <iostream>
    #include <Entity.hpp>

class TileMap : public Entity {
    public:
        TileMap(vec2f scale);
        TileMap(vec2f scale, const sf::Texture &t, char c, vec2f pos);
        ~TileMap();
        void createMap(char* path);
        void update(float dt) override;
        void handleEvents(sf::Event event) override;
    private:
        sf::IntRect _rect;
        sf::Sprite *_sprite;
        sf::Texture _texture;
        std::map<char, sf::IntRect> _rects = {
            { '.', { 0, 0, 48, 48 } },
            { 'x', { 0, 576, 48, 48 } },
            { 'o', { 0, 0, 48, 48 } },
            { 'p', { 0, 0, 48, 48 } },
            { 'q', { 0, 0, 48, 48 } },
            { 'r', { 0, 0, 48, 48 } },
            { 's', { 0, 0, 48, 48 } },
            { 't', { 0, 0, 48, 48 } },
            { 'u', { 0, 0, 48, 48 } },
            { 'v', { 0, 0, 48, 48 } },
            { 'w', { 0, 0, 48, 48 } },
            { 'y', { 0, 0, 48, 48 } },
            { 'z', { 0, 0, 48, 48 } },
            { 'A', { 0, 0, 48, 48 } },
            { 'B', { 0, 0, 48, 48 } },
            { 'C', { 0, 0, 48, 48 } },
            { 'D', { 0, 0, 48, 48 } },
            { 'E', { 0, 0, 48, 48 } },
            { 'F', { 0, 0, 48, 48 } },
            { 'G', { 0, 0, 48, 48 } },
            { 'H', { 0, 0, 48, 48 } },
            { 'I', { 0, 0, 48, 48 } },
            { 'J', { 0, 0, 48, 48 } },
            { 'K', { 0, 0, 48, 48 } },
            { 'L', { 0, 0, 48, 48 } },
            { 'M', { 0, 0, 48, 48 } },
            { 'N', { 0, 0, 48, 48 } },
            { 'O', { 0, 0, 48, 48 } },
            { 'P', { 0, 0, 48, 48 } },
            { 'Q', { 0, 0, 48, 48 } },
            { 'R', { 0, 0, 48, 48 } },
        };
};

#endif //TILEMAP_HPP
