#include <SceneManager.hpp>

SceneManager::SceneManager(vec2f scale)
{
    std::shared_ptr<Scene> menu = std::make_unique<Menu>(scale);
    std::shared_ptr<Scene> game = std::make_unique<Game>(scale);

    _scenes.push_back(menu);
    _scenes.push_back(game);

    *_currentScene = MENU;
}

SceneManager::~SceneManager()
{
}

void SceneManager::handleEvents(IRenderer &renderer)
{
    renderer.handleEvents(_scenes[*_currentScene], *_currentScene);
}

void SceneManager::updateScenes(float dt)
{
    _scenes[*_currentScene]->updateScene(dt);
}

void SceneManager::drawScenes(IRenderer &renderer)
{
    _scenes[*_currentScene]->drawScene(renderer);
}

void SceneManager::setScene(int scene)
{
    *_currentScene = scene;
}

size_t SceneManager::getScene()
{
    return *_currentScene;
}
