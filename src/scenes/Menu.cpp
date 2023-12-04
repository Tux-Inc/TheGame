#include <Menu.hpp>

Menu::Menu(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;
    _manager->addEntity(std::make_unique<P_button>(scale));
    _P_buttonId = _manager->getEntitiesSize();
    P_button* button = static_pointer_cast<P_button *>(_manager->getEntity(_P_buttonId));
    // button->setScene(_currentScene);
    
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

void Menu::setScene(int scene)
{
    *_currentScene = scene;
}
