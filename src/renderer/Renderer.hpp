#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include <IRenderer.hpp>
class IRenderer;
class Renderer : public IRenderer {
    public:
        Renderer() = default;
        ~Renderer();
        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void draw(const sf::Drawable &drawable) = 0;
        virtual void render() = 0;
        virtual void handleEvents(EntityManager &manager) = 0;
        virtual bool windowIsOpen() const = 0;
        virtual vec2f getScaleFactor() const = 0;
};

#endif /* !RENDERER_HPP_ */
