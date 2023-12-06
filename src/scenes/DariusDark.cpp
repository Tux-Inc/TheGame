#include <DariusDark.hpp>

DariusDark::DariusDark(vec2f scale)
{
    _manager = new EntityManager(scale);
    _musicManager = new MusicManager(50.0f);
    _soundManager = new SoundManager(50.0f);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    _tileSpriteId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) { 0, 0 }, (sf::Vector2f) { 1, 1 }, "./assets/img/runner_background.png", sf::IntRect({ 0, 0, 1920, 1080 })));
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale, (sf::Vector2f) { 50, 900 }));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale, (sf::Vector2f) { 1400, 900 }));
}

DariusDark::~DariusDark()
{
}

void DariusDark::drawScene(IRenderer &renderer)
{
    _musicManager->playMusics();
    _soundManager->playSounds();
    _manager->drawEntities(renderer);
}

void DariusDark::updateScene(float dt, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();
    // static int _offset = 0;
    // sf::IntRect rect = entities[_enemyId]->getRect(_enemyId);

    // Change rect of tileSprite every 0.1s to make it animated
    if (dt > 1) {
        sf::IntRect _rect = entities[_tileSpriteId]->getRect(_tileSpriteId);
        _rect.left += 1;
        if (_rect.left >= 1920)
            _rect.left = 0;
        entities[_tileSpriteId]->setRect(_rect, _tileSpriteId);
        // if (_offset == 32) {
        //     _offset = 0;
        // } else {
        //     _offset++;
        // }
        // rect.left = (_offset / 4) * 128;
        // entities[_enemyId]->setRect(rect, _enemyId);
    }

    // Direction dir = _manager->collision(entities[_playerId], entities[_tileSpriteId]);
    // if (dir != IDLE) {
    //     _manager->action(_playerId, STOP_MOVE, dir);
    // }
    // dir = _manager->collision(entities[_playerId], entities[_enemyId]);
    // if (dir != IDLE) {
    //     _manager->action(_playerId, STOP_MOVE, dir);
    //     _manager->action(_enemyId, STOP_MOVE, dir);
    // } else {
    //     _manager->action(_enemyId, START_MOVE, dir);
    // }
    // _manager->updateEntities(dt);
}

void DariusDark::handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
