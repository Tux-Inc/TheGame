#ifndef P_BUTTON_HPP_
#define P_BUTTON_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;
class IRenderer;

class P_button : public Entity {
    public:
        P_button(vec2f scale, const std::string &text, sf::Vector2f centerPos, const std::string &texturePath);
        // P_button(vec2f scale);
        ~P_button();
        void update(float dt) override;
        void handleEvents(sf::Event event);
        void action(ActionType action, Direction direction) override;
        void setScene(int scene);

    private:
        int _directions;
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        sf::Text *_sfText;
        sf::Font _font;
        std::string _text;
        int _offset;
        size_t _P_buttonId;
        sf::RectangleShape *_hitbox;
        size_t _hitboxId;
        size_t _textId;
        bool _hover;
        sf::RectangleShape *_boxBorder;
        size_t _borderId;
        bool _rotate;
};

#endif /* !P_button_HPP_ */
