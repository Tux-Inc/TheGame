#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <Game.hpp>
#include <IRenderer.hpp>
#include <Menu.hpp>
#include <Scene.hpp>
#include <memory>
#include <vector>

class SceneManager {

        enum SceneId {
            MENU,
            GAME
        };

    public:
        SceneManager(vec2f scale);
        ~SceneManager();
        void handleEvents(IRenderer &renderer);
        void drawScenes(IRenderer &renderer);

    protected:
    private:
        std::vector<std::shared_ptr<Scene>> _scenes;
        size_t _currentScene;
};

#endif /* !SCENEMANAGER_HPP_ */
