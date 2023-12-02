#ifndef MENU_HPP_
#define MENU_HPP_

#include <Scene.hpp>

class IRenderer;

class Menu : public Scene {
    public:
        Menu(vec2f scale);
        ~Menu();
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event);

    protected:
    private:
};

#endif /* !MENU_HPP_ */
