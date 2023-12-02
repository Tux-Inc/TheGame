#ifndef GAME_HPP_
#define GAME_HPP_

#include <Enemy.hpp>
#include <Player.hpp>
#include <Scene.hpp>

class IRenderer;
class Game : public Scene {
    public:
        Game(vec2f scale);
        ~Game();
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event);

    private:
        size_t _playerId;
        size_t _enemyId;
};

#endif /* !GAME_HPP_ */
