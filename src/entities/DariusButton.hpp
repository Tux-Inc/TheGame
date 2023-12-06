#ifndef DARIUSBUTTON_HPP_
#define DARIUSBUTTON_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;
class IRenderer;

class DariusButton : public Entity {
    public:
        DariusButton(vec2f scale, const std::string &text, sf::Vector2f centerPos, const std::string &texturePath);
        // DariusButton(vec2f scale);
        ~DariusButton();
        void update(float dt) override;
        void handleEvents(sf::Event event);
        void action(ActionType action, Direction direction, const std::string &text) override;
        void setScene(int scene);
        void reset() override;

    private:
        int _directions;
        sf::IntRect _rect;
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        sf::Text *_sfText;
        sf::Font _font;
        std::string _text;
        int _offset;
        size_t _dariusButtonId;
        sf::RectangleShape *_hitbox;
        size_t _hitboxId;
        size_t _textId;
        bool _hover;
        sf::RectangleShape *_boxBorder;
        size_t _borderId;
        bool _rotate;
};

#endif /* !DARIUSBUTTON_HPP_ */
