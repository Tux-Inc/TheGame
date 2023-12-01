#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <IEntity.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

class Entity: public IEntity {
    public:
        Entity() = default;
        ~Entity();
        virtual void update(float dt) = 0;
        void draw(IRenderer& renderer) override;
    protected:
        std::vector<sf::Drawable *> _drawables;
        vec2f _scaleFactor;
    private:
};

#endif /* !ENTITY_HPP_ */