#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <IEntity.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

class Entity : public IEntity {
    public:
        Entity() = default;
        ~Entity();
        virtual void update(float dt) = 0;
        void draw(IRenderer &renderer) override;
        void setPosition(sf::Vector2f pos) override;
        sf::Vector2f getPosition() const override;

    protected:
        sf::Drawable *_drawable;
        sf::Transformable *_transformable;
        vec2f _scaleFactor;
        sf::Vector2f _pos;

    private:
};

#endif /* !ENTITY_HPP_ */
