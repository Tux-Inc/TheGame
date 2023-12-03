#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
}

Menu::~Menu()
{
}

void Menu::updateScene(float dt)
{
    _manager->updateEntities(dt);
}

void Menu::drawScene(IRenderer &renderer)
{
    _manager->drawEntities(renderer);
}

void Menu::handleEvents(sf::Event event)
{
}
