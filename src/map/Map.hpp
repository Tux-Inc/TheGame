#ifndef MAP_HPP
#define MAP_HPP

#include <Entity.hpp>
#include <fstream>
#include <iostream>
#include <struct.h>
#include <vector>

class Map : public Entity {
    public:
        Map(vec2f scale);
        ~Map();
        void createMap(char *path);
        void update(float dt) override;
        void handleEvents(sf::Event event) override;

    private:
        std::vector<size_t> _tileIds;
};

#endif // MAP_HPP
