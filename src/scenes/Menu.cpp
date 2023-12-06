#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    sf::Vector2f dariusLightPos = (sf::Vector2f) { static_cast<float>((1920 / 2 - 400)), static_cast<float>(1080 / 2) };
    sf::Vector2f dariusDarkPos = (sf::Vector2f) { static_cast<float>((1920 / 2 + 700)), static_cast<float>(1080 / 2) };

    _backgroundId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) {0, 0}, (sf::Vector2f) {1, 1}, "./assets/img/background.png", sf::IntRect({0, 0, 1920, 1080})));
    _dariusLightId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "Get Chair", dariusLightPos, "./assets/img/dariusLight.png"));
    _dariusDarkId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "Runner", dariusDarkPos, "./assets/img/dariusDark.png"));
}

Menu::~Menu()
{
}

void Menu::updateScene(float dt, size_t &currentScene)
{
    _manager->updateEntities(dt);
}

void Menu::drawScene(IRenderer &renderer)
{
    _manager->drawEntities(renderer);
}

void Menu::handleEvents(sf::Event event, size_t &currentScene)
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
