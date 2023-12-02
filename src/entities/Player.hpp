#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;

class Player : public Entity {

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
};

#endif /* !PLAYER_HPP_ */
