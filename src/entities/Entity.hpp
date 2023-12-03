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
        virtual void handleEvents(sf::Event event) = 0;
        void setPosition(sf::Vector2f pos, size_t assetId) override;
        sf::Vector2f getPosition(size_t assetId) const override;

    protected:
        std::vector<sf::Drawable *> _drawables;
        std::vector<sf::Transformable *> _transformables;
        vec2f _scaleFactor;
        sf::Vector2f _pos;
        sf::Vector2f _hitboxPos;
        bool _debug;

    private:
};

#endif /* !ENTITY_HPP_ */
