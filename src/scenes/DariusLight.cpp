#include <DariusLight.hpp>

DariusLight::DariusLight(vec2f scale)
{
    _manager = new EntityManager(scale);
    _musicManager = new MusicManager(50.0f);
    _soundManager = new SoundManager(50.0f);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _active = false;
    _elapsedTime = 0;

    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
    _nextTime = _end + std::chrono::seconds(1);

    _musicManager->addMusic(std::make_unique<MyMusic>("./assets/music/megalovania.ogg", 100.0f));
    _soundManager->addSound(std::make_unique<MySound>("./assets/sound/coin.ogg", 100.0f));
    _manager->addEntity(std::make_unique<Map>(scale));
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale, (sf::Vector2f) { 100, 100 }));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale, (sf::Vector2f) { 300, 300 }));
    _tileSpriteId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) { 1000, 100 }));
    _timeTitleId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Text>(scale, "TIME", (sf::Vector2f) { 1800, 100 }, sf::Color::White));
    _timeId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Text>(scale, "0", (sf::Vector2f) { 1800, 150 }, sf::Color::White));
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
    if (!_active) {
        _elapsedTime = 0;
        _start = std::chrono::steady_clock::now();
        _end = std::chrono::steady_clock::now();
        _nextTime = _end + std::chrono::seconds(1);
        _active = true;
    }
    if (_elapsedTime >= 60) {
        this->resetScene();
        previousScene = currentScene;
        currentScene = GAMEOVER;
    }
    _end = std::chrono::steady_clock::now();
    if (_end >= _nextTime) {
        _nextTime = _end + std::chrono::seconds(1);
        float duration = std::chrono::duration_cast<std::chrono::duration<float>>(_end - _start).count();
        std::cout << duration << std::endl;
        _elapsedTime = (int)duration;
        std::string sTimer = std::to_string(_elapsedTime);
        _manager->action(_timeId, CHANGETEXT, Direction::IDLE, sTimer);
    }

    Direction dir = _manager->collision(entities[_playerId], entities[_tileSpriteId]);
    if (dir != IDLE) {
        _manager->action(_playerId, STOP_MOVE, dir, "");
    }
    dir = _manager->collision(entities[_playerId], entities[_enemyId]);
    if (dir != IDLE) {
        _manager->action(_playerId, STOP_MOVE, dir, "");
        _manager->action(_enemyId, STOP_MOVE, dir, "");
    } else {
        _manager->action(_enemyId, START_MOVE, dir, "");
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
