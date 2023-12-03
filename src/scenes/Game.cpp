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
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    Direction dir = _manager->collision(entities[_playerId], entities[_coneId]);
    if (dir != IDLE) {
        _manager->action(_playerId, STOP_MOVE, dir);
    }
    dir = _manager->collision(entities[_playerId], entities[_enemyId]);
    if (dir != IDLE) {
        _manager->action(_playerId, STOP_MOVE, dir);
        _manager->action(_enemyId, STOP_MOVE, dir);
    } else {
        _manager->action(_enemyId, START_MOVE, dir);
    }
    _manager->updateEntities(dt);
}

void Game::handleEvents(sf::Event event)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
