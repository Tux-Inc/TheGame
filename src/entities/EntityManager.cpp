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
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            sf::Vector2f pos = getPosition(0);
            pos.x -= 10 * _scaleFactor.x;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Right) {
            sf::Vector2f pos = getPosition(0);
            pos.x += 10 * _scaleFactor.x;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Up) {
            sf::Vector2f pos = getPosition(0);
            pos.y -= 10 * _scaleFactor.y;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Down) {
            sf::Vector2f pos = getPosition(0);
            pos.y += 10 * _scaleFactor.y;
            setPosition(pos, 0);
        }
    }
}

sf::Vector2f EntityManager::getPosition(size_t entityId)
{
    sf::Vector2f pos = _entities[entityId]->getPosition();
    return pos;
}

void EntityManager::setPosition(sf::Vector2f pos, size_t entityId)
{
    _entities[entityId]->setPosition(pos);
}
