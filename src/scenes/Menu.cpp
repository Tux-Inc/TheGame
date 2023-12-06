#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _active = false;
    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
    _nextTime = _end + std::chrono::seconds(1);
    _elapsedTime = 0;

    sf::Vector2f dariusLightPos = (sf::Vector2f) { (float)((1920 / 8) * 2), (float)(1080 / 2) };
    sf::Vector2f dariusDarkPos = (sf::Vector2f) { (float)((1920 / 8) * 6), 1080 / 2 };
    sf::Vector2f dariusLightTitlePos = (sf::Vector2f) { (float)(dariusLightPos.x), (float)(dariusLightPos.y - 261 - 100) };
    sf::Vector2f dariusDarkTitlePos = (sf::Vector2f) { (float)(dariusDarkPos.x), (float)(dariusDarkPos.y - 261 - 100) };

    _backgroundId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) { 0, 0 }, (sf::Vector2f) { 1, 1 }, "./assets/img/background.png", sf::IntRect({ 0, 0, 1920, 1080 })));
    _dariusLightId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<DariusButton>(scale, "", dariusLightPos, "./assets/img/dariusLight.png"));
    _dariusDarkId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<DariusButton>(scale, "", dariusDarkPos, "./assets/img/dariusDark.png"));
    _dariusLightTitleId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Text>(scale, "GET CHAIR", dariusLightTitlePos, sf::Color::Magenta));
    _dariusDarkTitleId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<Text>(scale, "RUNNER", dariusDarkTitlePos, sf::Color::Black));
}

Menu::~Menu()
{
}

void Menu::updateScene(float dt, size_t &currentScene, size_t &previousScene)
{
    if (!_active) {
        _start = std::chrono::steady_clock::now();
        _end = std::chrono::steady_clock::now();
        _nextTime = _end + std::chrono::seconds(1);
        _active = true;
    }
    _manager->updateEntities(dt);
}

void Menu::drawScene(IRenderer &renderer)
{
    _manager->drawEntities(renderer);
}

void Menu::handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();
    if (entities[_dariusLightId]->clicked()) {
        currentScene = GAME1;
    }
    if (entities[_dariusDarkId]->clicked()) {
        currentScene = GAME2;
    }
    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
