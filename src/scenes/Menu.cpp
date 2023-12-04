#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    // _P_buttonId = _manager->getEntitiesSize();
    // _manager->addEntity(std::make_unique<P_button>(scale, "PLAY", (sf::Vector2f) { (float)1920 / 2, 200 }, "./assets/img/button.png"));
    sf::Vector2f dariusLightPos = (sf::Vector2f) { (float)((1920 / 8) * 2), (float)(1080 / 2) };
    sf::Vector2f dariusDarkPos = (sf::Vector2f) { (float)((1920 / 8) * 6), 1080 / 2 };
    _dariusLightId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "", dariusLightPos, "./assets/img/dariusLight.png"));
    _dariusDarkId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "", dariusDarkPos, "./assets/img/dariusDark.png"));
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
