#include <SceneManager.hpp>

SceneManager::SceneManager(vec2f scale)
{
    std::shared_ptr<Scene> menu = std::make_unique<Menu>(scale);
    std::shared_ptr<Scene> game1 = std::make_unique<DariusLight>(scale);
    std::shared_ptr<Scene> game2 = std::make_unique<DariusDark>(scale);
    std::shared_ptr<Scene> gameOver = std::make_unique<GameOver>(scale);

    _scenes.push_back(menu);
    _scenes.push_back(game1);
    _scenes.push_back(game2);
    _scenes.push_back(gameOver);

    _currentScene = MENU;
    _previousScene = MENU;
}

SceneManager::~SceneManager()
{
}

void SceneManager::handleEvents(IRenderer &renderer)
{
    renderer.handleEvents(_scenes[_currentScene], _currentScene, _previousScene);
}

void SceneManager::updateScenes(float dt)
{
    _scenes[_currentScene]->updateScene(dt, _currentScene, _previousScene);
}

void SceneManager::drawScenes(IRenderer &renderer)
{
    _scenes[_currentScene]->drawScene(renderer);
}
