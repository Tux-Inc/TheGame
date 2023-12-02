#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <IRenderer.hpp>
#include <SFML/Graphics.hpp>

class IRenderer;

class IEntity {
    public:
        virtual ~IEntity() { }
        virtual void update(float dt) = 0;
        virtual void draw(IRenderer &renderer) = 0;
        virtual void setPosition(sf::Vector2f pos) = 0;
        virtual sf::Vector2f getPosition() const = 0;
};

#endif /* !IENTITY_HPP_ */
