#include <Game.hpp>

Game::Game(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _manager->addEntity(std::make_unique<Map>(scale));
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale));
    _coneId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Cone>(scale));
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

void Game::setScene(int scene)
{
    *_currentScene = scene;
}

void Game::handleEvents(sf::Event event)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
