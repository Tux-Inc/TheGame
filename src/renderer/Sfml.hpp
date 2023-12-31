#ifndef SFML_HPP_
#define SFML_HPP_

#include <Renderer.hpp>
#include <SFML/Graphics.hpp>
#include <transform.h>

class IRenderer;

class Sfml : public Renderer {
    public:
        Sfml();
        ~Sfml() override;
        void init() override;
        void clear() override;
        void draw(const sf::Drawable &drawable) override;
        void render() override;
        void handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene, size_t &previousScene) override;
        bool windowIsOpen() const override;
        vec2f getScaleFactor() const override;

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        vec2f _scaleFactor;
        uint32_t _w;
        uint32_t _h;
};

#endif /* !SFML_HPP_ */
