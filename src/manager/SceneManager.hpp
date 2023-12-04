#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <Clock.hpp>
#include <DariusDark.hpp>
#include <DariusLight.hpp>
#include <IRenderer.hpp>
#include <Menu.hpp>
#include <Scene.hpp>
#include <memory>
#include <vector>

class SceneManager {

    public:
        SceneManager(vec2f scale);
        ~SceneManager();
        void handleEvents(IRenderer &renderer);
        void updateScenes(float dt);
        void drawScenes(IRenderer &renderer);

    protected:
    private:
        std::vector<std::shared_ptr<Scene>> _scenes;
        size_t _currentScene;
};

#endif /* !SCENEMANAGER_HPP_ */
