#include <Core.hpp>

Core::Core()
{
    _renderer = new Sfml();
    _sceneManager = new SceneManager(_renderer->getScaleFactor());
}

Core::~Core()
{
}

void Core::run()
{
    gameLoop();
}

void Core::gameLoop()
{
    while (_renderer->windowIsOpen()) {

        float dt = _clock.Tick();

        _sceneManager->handleEvents(*_renderer);

        _renderer->clear();

        _sceneManager->updateScenes(dt);

        _sceneManager->drawScenes(*_renderer);

        _renderer->render();
    }
}
