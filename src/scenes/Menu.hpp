#ifndef MENU_HPP_
#define MENU_HPP_

#include <Clock.hpp>
#include <P_button.hpp>
#include <Scene.hpp>

class IRenderer;

class Menu : public Scene {
    public:
        Menu(vec2f scale);
        ~Menu();
        void updateScene(float dt, size_t &currentScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene) override;

    private:
        size_t _P_buttonId;
};

#endif /* !MENU_HPP_ */
