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
        void action(ActionType action, Direction direction) override;

    protected:
    private:
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        size_t _spriteId;
};

#endif /* !CONE_HPP_ */
