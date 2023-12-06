#include <DariusLight.hpp>

DariusLight::DariusLight(vec2f scale)
{
    _manager = new EntityManager(scale);
    _musicManager = new MusicManager(50.0f);
    _soundManager = new SoundManager(50.0f);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    _musicManager->addMusic(std::make_unique<MyMusic>("./assets/music/megalovania.ogg", 100.0f));
    _soundManager->addSound(std::make_unique<MySound>("./assets/sound/coin.ogg", 100.0f));
    _manager->addEntity(std::make_unique<Map>(scale));
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale, (sf::Vector2f) { 100, 100 }));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale, (sf::Vector2f) { 300, 300 }));
    _tileSpriteId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) { 1000, 100 }));
}

DariusLight::~DariusLight()
{
}

void DariusLight::drawScene(IRenderer &renderer)
{
    _musicManager->playMusics();
    _soundManager->playSounds();
    _manager->drawEntities(renderer);
}

void DariusLight::updateScene(float dt, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    Direction dir = _manager->collision(entities[_playerId], entities[_tileSpriteId]);
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

void DariusLight::handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }

    if (_manager->collision(entities[_playerId], entities[_enemyId]) != IDLE) {
        this->resetScene();
        previousScene = currentScene;
        currentScene = GAMEOVER;
    }

    if (_manager->collision(entities[_playerId], entities[_tileSpriteId]) != IDLE) {
        this->resetScene();
        previousScene = currentScene;
        currentScene = GAMEOVER;
    }
}
