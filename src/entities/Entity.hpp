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
        void setRect(sf::IntRect rect, size_t assetId) override;
        sf::IntRect getRect(size_t assetId) const override;
        Direction intersects(std::shared_ptr<IEntity> other) override;
        sf::RectangleShape &getHitbox() const;
        virtual void action(ActionType action, Direction direction) = 0;
        Direction getDirection() const override;
        Direction getPreviousDirection() const override;
        sf::Vector2f getHitboxPosition() const;
        sf::Vector2f getPrevHitboxPosition() const;
        bool clicked() const override;
        virtual void reset() = 0;

    protected:
        std::vector<sf::Drawable *> _drawables;
        std::vector<sf::Transformable *> _transformables;
        vec2f _scaleFactor;
        sf::Vector2f _pos;
        sf::Vector2f _startPos;
        sf::Vector2f _hitboxPos;
        sf::Vector2f _prevHitboxPos;
        bool _debug;
        bool _collides;
        sf::RectangleShape *_hitbox;
        size_t _hitboxId;
        Direction _direction;
        Direction _prevDir;
        bool _clicked;

    private:
};

#endif /* !ENTITY_HPP_ */
