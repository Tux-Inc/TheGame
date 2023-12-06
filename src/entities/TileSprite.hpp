#ifndef TILESPRITE_HPP_
#define TILESPRITE_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;

class TileSprite : public Entity {
    public:
        TileSprite(vec2f scale, sf::Vector2f pos);
        TileSprite(vec2f scale, sf::Vector2f pos, sf::Vector2f rescale, std::string texturePath, sf::IntRect rect);
        ~TileSprite();
        void update(float dt) override;
        void handleEvents(sf::Event event);
        void action(ActionType action, Direction direction) override;
        void reset() override;

    protected:
    private:
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        size_t _spriteId;
};

#endif /* !TILESPRITE_HPP_ */
