#include <Game.hpp>

Game::Game(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale));
}

Game::~Game()
{
}

void Game::drawScene(IRenderer &renderer)
{
    _manager->drawEntities(renderer);
}

void Game::updateScene(float dt)
{
    _manager->updateEntities(dt);
}

void Game::handleEvents(sf::Event event)
{
    std::shared_ptr<IEntity> player = _manager->getEntity(_playerId);
    player->handleEvents(event);
}
