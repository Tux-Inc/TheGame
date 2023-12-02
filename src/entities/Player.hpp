#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;

class Player : public Entity {

        enum Walk {
            UP = 8,
            LEFT = 9,
            DOWN = 10,
            RIGHT = 11
        };

        enum Directions {
            Up = 1 << 0, // 0001
            Down = 1 << 1, // 0010
            Left = 1 << 2, // 0100
            Right = 1 << 3, // 1000
        };

    public:
        Player(vec2f scale);
        ~Player();
        void update(float dt) override;
        void updatePosition(float dt);
        void handleEvents(sf::Event event);

    private:
        int _directions;
        sf::Vector2f _velocity;
        float _speed;
        Walk _dir;
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
};

#endif /* !PLAYER_HPP_ */
