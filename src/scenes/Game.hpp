#ifndef GAME_HPP_
    #define GAME_HPP_

    #include <Map.hpp>
    #include <Clock.hpp>
    #include <Enemy.hpp>
    #include <Scene.hpp>
    #include <Player.hpp>

class IRenderer;

class Game : public Scene {
    public:
        Game(vec2f scale);
        ~Game();
        void updateScene(float dt) override;
        void drawScene(IRenderer &renderer) override;
        void handleEvents(sf::Event event) override;

    private:
        size_t _playerId;
        size_t _enemyId;
};

#endif /* !GAME_HPP_ */
