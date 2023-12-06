#ifndef MENU_HPP_
#define MENU_HPP_

#include <Clock.hpp>
#include <DariusButton.hpp>
#include <Scene.hpp>
#include <Text.hpp>
#include <TileSprite.hpp>

class IRenderer;

class Menu : public Scene {
    public:
        Menu(vec2f scale);
        ~Menu();
        void updateScene(float dt, size_t &currentScene, size_t &previousScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene) override;

    private:
        size_t _backgroundId;
        size_t _P_buttonId;
        size_t _dariusLightId;
        size_t _dariusDarkId;
        size_t _dariusLightTitleId;
        size_t _dariusDarkTitleId;
};

#endif /* !MENU_HPP_ */
