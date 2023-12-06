#ifndef IRENDERER_HPP_
#define IRENDERER_HPP_

#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
#include <memory>
#include <struct.h>

class Scene;
class MusicManager;
class EntityManager;

class IRenderer {
    public:
        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void draw(const sf::Drawable &drawable) = 0;
        virtual void render() = 0;
        virtual void handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene, size_t &previousScene) = 0;
        virtual bool windowIsOpen() const = 0;
        virtual vec2f getScaleFactor() const = 0;
        virtual ~IRenderer() = default;
};

#endif /* !IRENDERER_HPP_ */
