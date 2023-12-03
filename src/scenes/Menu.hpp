#ifndef MENU_HPP_
#define MENU_HPP_

#include <Clock.hpp>
#include <Scene.hpp>

class IRenderer;

class Menu : public Scene {
    public:
        Menu(vec2f scale);
        ~Menu();
        void updateScene(float dt) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event) override;

    protected:
    private:
};

#endif /* !MENU_HPP_ */
