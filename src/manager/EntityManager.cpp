#include <EntityManager.hpp>

EntityManager::EntityManager(vec2f scale)
{
    _scaleFactor = scale;
}

EntityManager::~EntityManager()
{
}

void EntityManager::addEntity(std::shared_ptr<IEntity> entity)
{
    _entities.push_back(entity);
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

void EntityManager::handleEvents(const sf::Event &event)
{
}

std::shared_ptr<IEntity> EntityManager::getEntity(size_t entityId)
{
    return _entities[entityId];
}

std::vector<std::shared_ptr<IEntity>> EntityManager::getEntities()
{
    return _entities;
}

size_t EntityManager::getEntitiesSize() const
{
    return _entities.size();
}

Direction EntityManager::collision(std::shared_ptr<IEntity> e1, std::shared_ptr<IEntity> e2)
{
    return e1->intersects(e2);
}

void EntityManager::action(size_t entityId, ActionType action, Direction direction)
{
    _entities[entityId]->action(action, direction);
}
