#ifndef DARIUSLIGHT_HPP_
#define DARIUSLIGHT_HPP_

#include <Clock.hpp>
#include <TileSprite.hpp>
#include <Enemy.hpp>
#include <Map.hpp>
#include <MyMusic.hpp>
#include <MySound.hpp>
#include <Player.hpp>
#include <Scene.hpp>

class IRenderer;

class DariusLight : public Scene {
    public:
        DariusLight(vec2f scale);
        ~DariusLight();
        void updateScene(float dt, size_t &currentScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene) override;
        void resetScene();

    private:
        size_t _playerId;
        size_t _enemyId;
        size_t _tileSpriteId;
};

#endif /* !DARIUSLIGHT_HPP_ */
