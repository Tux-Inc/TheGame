#ifndef GAME_HPP_
#define GAME_HPP_

#include <Clock.hpp>
#include <Cone.hpp>
#include <Enemy.hpp>
#include <Map.hpp>
#include <Player.hpp>
#include <Scene.hpp>
#include <MyMusic.hpp>
#include <MySound.hpp>

class IRenderer;

class Game : public Scene {
    public:
        Game(vec2f scale);
        ~Game();
        void updateScene(float dt, size_t &currentScene) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event, size_t &currentScene) override;

    private:
        size_t _playerId;
        size_t _enemyId;
        size_t _coneId;
};

#endif /* !GAME_HPP_ */
