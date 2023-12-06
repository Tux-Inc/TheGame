#include <GameOver.hpp>

GameOver::GameOver(vec2f scale)
{
    _manager = new EntityManager(scale);
    _scaleFactor.x = scale.x;
    _scaleFactor.y = scale.y;

    sf::Vector2f restartPos = (sf::Vector2f) { static_cast<float>((1920 / 2)), static_cast<float>((1080 / 2) - 65) };
    sf::Vector2f menuPos = (sf::Vector2f) { static_cast<float>((1920 / 2)), static_cast<float>((1080 / 2) + 65) };

    _backgroundId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<TileSprite>(scale, (sf::Vector2f) { 0, 0 }, (sf::Vector2f) { 1, 1 }, "./assets/img/background.png", sf::IntRect({ 0, 0, 1920, 1080 })));
    _restartButtonId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "RESTART", restartPos, "./assets/img/button.png"));
    _menuButtonId = _manager->getEntitiesSize();
    _manager->addEntity(std::make_unique<P_button>(scale, "MENU", menuPos, "./assets/img/button.png"));
}

GameOver::~GameOver()
{
}

void GameOver::updateScene(float dt, size_t &currentScene, size_t &previousScene)
{
    _manager->updateEntities(dt);
}

void GameOver::drawScene(IRenderer &renderer)
{
    _manager->drawEntities(renderer);
}

void GameOver::handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene)
{
    std::vector<std::shared_ptr<IEntity>> entities = _manager->getEntities();
    if (entities[_restartButtonId]->clicked()) {
        this->resetScene();
        size_t tmp = previousScene;
        previousScene = currentScene;
        currentScene = tmp;
    }
    if (entities[_menuButtonId]->clicked()) {
        this->resetScene();
        previousScene = currentScene;
        currentScene = MENU;
    }
    for (auto &&entity : entities) {
        entity->handleEvents(event);
    }
}
