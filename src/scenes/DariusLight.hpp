#ifndef DARIUSLIGHT_HPP_
#define DARIUSLIGHT_HPP_

#include <Clock.hpp>
#include <Enemy.hpp>
#include <Map.hpp>
#include <MyMusic.hpp>
#include <MySound.hpp>
#include <Player.hpp>
#include <Scene.hpp>
#include <Text.hpp>
#include <TileSprite.hpp>

class IRenderer;

class DariusLight : public Scene {
    public:
        DariusLight(vec2f scale);
        ~DariusLight();
        void updateScene(float dt, size_t &currentScene, size_t &previousScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene) override;

    private:
        size_t _playerId;
        size_t _enemyId;
        size_t _tileSpriteId;
        size_t _timeTitleId;
        size_t _timeId;
};

#endif /* !DARIUSLIGHT_HPP_ */
