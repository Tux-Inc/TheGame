#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;
class IRenderer;

class Enemy : public Entity {
    public:
        Enemy(vec2f scale);
        ~Enemy();
        void update(float dt) override;

    private:
};

#endif /* !ENEMY_HPP_ */
