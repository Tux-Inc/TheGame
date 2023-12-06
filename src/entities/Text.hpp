#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <Entity.hpp>
#include <transform.h>

class IEntity;
class IRenderer;

class Text : public Entity {
    public:
        Text(vec2f scale, const std::string &text, sf::Vector2f centerPos, sf::Color color);
        // Text(vec2f scale);
        ~Text();
        void update(float dt) override;
        void handleEvents(sf::Event event);
        void action(ActionType action, Direction direction) override;
        void setScene(int scene);
        void reset() override;

    private:
        int _directions;
        sf::IntRect _rect;
        sf::Text *_sfText;
        sf::Font _font;
        std::string _text;
        int _offset;
        size_t _TextId;
        size_t _hitboxId;
        size_t _textId;
        bool _hover;
};

#endif /* !TEXT_HPP_ */
