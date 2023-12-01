#ifndef IRENDERER_HPP_
#define IRENDERER_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

class IRenderer {
public:
    virtual void init() = 0;
    virtual void clear() = 0;
    virtual void draw(const sf::Drawable& drawable) = 0;
    virtual void render() = 0;
    virtual void handleEvents() = 0;
    virtual bool windowIsOpen() const = 0;
    virtual ~IRenderer() = default;
};

#endif /* !IRENDERER_HPP_ */