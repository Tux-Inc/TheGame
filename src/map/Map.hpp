#ifndef MAP_HPP
    #define MAP_HPP

    #include <vector>
    #include <fstream>
    #include <iostream>
    #include <struct.h>
    #include <Entity.hpp>

class Map : public Entity {
    public:
        Map(vec2f scale);
        ~Map();
        void createMap(char* path);
        void draw(IRenderer &renderer) override;
        void update(float dt) override;
        void handleEvents(sf::Event event) override;
    private:
        std::vector<sf::Drawable *> _drawables;
};



#endif //MAP_HPP
