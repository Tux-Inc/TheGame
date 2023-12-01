#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <IEntity.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Entity: public IEntity {
    public:
        Entity();
        ~Entity();
        virtual void update(float dt) = 0;
        void draw(IRenderer& renderer) override;
    protected:
        std::vector<sf::Drawable *> _drawables;
    private:
};

#endif /* !ENTITY_HPP_ */