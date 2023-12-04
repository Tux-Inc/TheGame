#ifndef MENU_HPP_
#define MENU_HPP_

#include <Clock.hpp>
#include <Scene.hpp>
#include <P_button.hpp>

class IRenderer;

class Menu : public Scene {
    public:
        Menu(vec2f scale);
        ~Menu();
        void updateScene(float dt) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event) override;
        void setScene(int scene) override;

    private:
        size_t _P_buttonId;
};

#endif /* !MENU_HPP_ */
