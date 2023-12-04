#ifndef P_BUTTON_HPP_
#define P_BUTTON_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;
class IRenderer;

class P_button : public Entity {
    public:
        P_button(vec2f scale);
        ~P_button();
        void update(float dt) override;
        void handleEvents(sf::Event event);
        void setScene(int scene);

    private:
        int _directions;
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        int _offset;
        size_t _P_buttonId;
        sf::RectangleShape *_hitbox;
        size_t _hitboxId;
        int *_currentScene;
};

#endif /* !P_button_HPP_ */
