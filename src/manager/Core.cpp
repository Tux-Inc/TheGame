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

        _sceneManager->handleEvents(*_renderer);

        _renderer->clear();

        _sceneManager->drawScenes(*_renderer);

        _renderer->render();
    }
}
