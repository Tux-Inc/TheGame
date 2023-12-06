#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include <Clock.hpp>
#include <P_button.hpp>
#include <Scene.hpp>
#include <TileSprite.hpp>

class IRenderer;

class GameOver : public Scene {
    public:
        GameOver(vec2f scale);
        ~GameOver();
        void updateScene(float dt, size_t &currentScene, size_t &previousScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene) override;

    private:
        size_t _backgroundId;
        size_t _restartButtonId;
        size_t _menuButtonId;
};

#endif /* !GAMEOVER_HPP_ */
