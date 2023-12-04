#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _P_buttonId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "PLAY", (sf::Vector2f) { (float)1920 / 2, 200 }));
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
    if (entities[_P_buttonId]->clicked()) {
        currentScene = GAME;
    }
    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
