#include <Scene.hpp>

Scene::~Scene()
{
}

void Scene::resetScene()
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();
    _elapsedTime = 0;
    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
    _nextTime = _end + std::chrono::seconds(1);
    _active = false;
    for (size_t i = 0; i < entities.size(); i++) {
        entities[i]->reset();
    }
}
