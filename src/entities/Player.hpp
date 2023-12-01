#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <transform.h>
#include <Entity.hpp>

class Player: public Entity {
    public:
        Player();
        ~Player();
        void update(float dt) override;
    private:
        sf::Vector2f _pos;
};

#endif /* !PLAYER_HPP_ */
