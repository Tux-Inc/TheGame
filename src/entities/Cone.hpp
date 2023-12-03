#ifndef CONE_HPP_
#define CONE_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;

class Cone : public Entity {
    public:
        Cone(vec2f scale);
        ~Cone();
        void update(float dt) override;
        void handleEvents(sf::Event event);

    protected:
    private:
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        size_t _spriteId;
        sf::RectangleShape *_hitbox;
        size_t _hitboxId;
};

#endif /* !CONE_HPP_ */
