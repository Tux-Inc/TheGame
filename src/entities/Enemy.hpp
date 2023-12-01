#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <transform.h>
#include <Entity.hpp>

class Enemy: public Entity {
    public:
        Enemy();
        ~Enemy();
        void update(float dt) override;
    private:
        sf::Vector2f _pos;
};

#endif /* !ENEMY_HPP_ */
