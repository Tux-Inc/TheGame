#include <Scene.hpp>

Scene::~Scene()
{
}

void Scene::resetScene()
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (size_t i = 0; i < entities.size(); i++) {
        entities[i]->reset();
    }
}
