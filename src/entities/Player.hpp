#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Entity.hpp>
#include <transform.h>

class Player: public Entity {
    public:
        Player(vec2f scale);
        ~Player();
        void update(float dt) override;
    private:
        sf::Vector2f _pos;
};

#endif /* !PLAYER_HPP_ */
