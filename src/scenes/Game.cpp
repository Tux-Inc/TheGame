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

void Game::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            sf::Vector2f pos = _manager->getPosition(_playerId);
            pos.x -= 10 * _scaleFactor.x;
            _manager->setPosition(pos, _playerId);
        }
        if (event.key.code == sf::Keyboard::Right) {
            sf::Vector2f pos = _manager->getPosition(_playerId);
            pos.x += 10 * _scaleFactor.x;
            _manager->setPosition(pos, _playerId);
        }
        if (event.key.code == sf::Keyboard::Up) {
            sf::Vector2f pos = _manager->getPosition(_playerId);
            pos.y -= 10 * _scaleFactor.y;
            _manager->setPosition(pos, _playerId);
        }
        if (event.key.code == sf::Keyboard::Down) {
            sf::Vector2f pos = _manager->getPosition(_playerId);
            pos.y += 10 * _scaleFactor.y;
            _manager->setPosition(pos, _playerId);
        }
    }
}
