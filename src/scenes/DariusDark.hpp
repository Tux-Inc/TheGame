#ifndef DARIUSDARK_HPP_
#define DARIUSDARK_HPP_

#include <Map.hpp>
#include <Scene.hpp>
#include <Clock.hpp>
#include <Enemy.hpp>
#include <Player.hpp>
#include <MyMusic.hpp>
#include <MySound.hpp>
#include <TileSprite.hpp>

class IRenderer;

class DariusDark : public Scene {
    public:
        DariusDark(vec2f scale);
        ~DariusDark();
        void updateScene(float dt, size_t &currentScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene) override;

    private:
        size_t _playerId;
        size_t _enemyId;
        size_t _tileSpriteId;
};

#endif /* !GAME_HPP_ */
