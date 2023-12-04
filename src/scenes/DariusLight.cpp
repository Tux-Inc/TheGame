#include <DariusLight.hpp>

DariusLight::DariusLight(vec2f scale)
{
    _manager = new EntityManager(scale);
    _musicManager = new MusicManager(50.0f);
    _soundManager = new SoundManager(50.0f);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    // std::string line;
    // const std::string path = "./assets/maps/main_game";
    // std::ifstream inputFile(path);
    // sf::Texture t;
    // t.loadFromFile("./assets/img/map_futuristique.png");
    // for (int y = 0; std::getline(inputFile, line); y++) {
    //     for (int x = 0; line[x]; x++) {
    //         _manager->addEntity(std::make_unique<TileMap>(scale, t, line[x], (vec2f) { static_cast<float>(x * 48), static_cast<float>(y * 48) }));
    //     }
    // }

    _musicManager->addMusic(std::make_unique<MyMusic>("./assets/music/megalovania.ogg", 100.0f));
    _soundManager->addSound(std::make_unique<MySound>("./assets/sound/coin.ogg", 100.0f));
    _manager->addEntity(std::make_unique<Map>(scale));
    _playerId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Player>(scale, (sf::Vector2f) { 100, 100 }));
    _enemyId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Enemy>(scale, (sf::Vector2f) { 300, 300 }));
    _coneId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Cone>(scale, (sf::Vector2f) { 1000, 100 }));
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

void DariusLight::updateScene(float dt, size_t &currentScene)
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

void DariusLight::handleEvents(sf::Event event, size_t &currentScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();

    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}