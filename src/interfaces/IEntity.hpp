#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <IRenderer.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <struct.h>

class IRenderer;

class IEntity {
    public:
        virtual ~IEntity() { }
        virtual void update(float dt) = 0;
        virtual void draw(IRenderer &renderer) = 0;
        virtual void handleEvents(sf::Event event) = 0;
        virtual void setPosition(sf::Vector2f pos, size_t assetId) = 0;
        virtual sf::Vector2f getPosition(size_t assetId) const = 0;
        virtual Direction intersects(std::shared_ptr<IEntity> other) = 0;
        virtual sf::RectangleShape &getHitbox() const = 0;
        virtual sf::Vector2f getHitboxPosition() const = 0;
        virtual sf::Vector2f getPrevHitboxPosition() const = 0;
        virtual void action(ActionType action, Direction direction) = 0;
        virtual Direction getDirection() const = 0;
        virtual Direction getPreviousDirection() const = 0;
};

#endif /* !IENTITY_HPP_ */
