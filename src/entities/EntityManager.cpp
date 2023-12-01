#include <EntityManager.hpp>

EntityManager::EntityManager()
{
    std::cout << "Entity manager created" << std::endl;
}

EntityManager::~EntityManager()
{
}

void EntityManager::addEntity(std::shared_ptr<IEntity> entity)
{
    _entities.push_back(entity);
    std::cout << "Added entity to Entity Manager" << std::endl;
}

void EntityManager::updateEntities(float dt)
{
    for (size_t i = 0; i < _entities.size(); i++) {
        _entities[i]->update(dt);
    }
}

void EntityManager::drawEntities(IRenderer &renderer)
{
    for (size_t i = 0; i < _entities.size(); i++) {
        _entities[i]->draw(renderer);
    }
}
