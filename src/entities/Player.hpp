#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;

class Player : public Entity {
    public:
        Player(vec2f scale);
        ~Player();
        void update(float dt) override;

    private:
};

#endif /* !PLAYER_HPP_ */
