#include "Map.hpp"

Map::Map(vec2f scale)
{
    _scaleFactor = scale;

    const std::string path = "./assets/maps/main_game";
    std::string line;

    auto *t = new sf::Texture();
    t->loadFromFile("./assets/img/map_futuristique.png");

    std::ifstream inputFile(path);
    _direction = IDLE;

    for (int y = 0; std::getline(inputFile, line); y++) {
        for (int x = 0; line[x]; x++) {
            sf::IntRect rect({ 0, 0, 48, 48 });
            auto *s = new sf::Sprite(*t);
            _pos = scaleVector((sf::Vector2f) { static_cast<float>(x * 48), static_cast<float>(y * 48) }, _scaleFactor);
            switch (line[x]) {
            case '.':
                rect = { 0, 0, 48, 48 };
                break;
            case 'x':
                rect = { 0, 48, 48, 48 };
                break;
            default:
                break;
            }
            s->setPosition(_pos);
            s->setTextureRect(rect);
            s->setScale((sf::Vector2f) { _scaleFactor.x, _scaleFactor.y });
            _tileIds.push_back(_drawables.size());
            _drawables.push_back(s);
            _transformables.push_back(s);
        }
    }
}

Map::~Map()
{
}

void Map::update(float dt)
{
}

void Map::handleEvents(sf::Event event)
{
}

void Map::action(ActionType action, Direction direction, const std::string &text)
{
}

void Map::reset()
{
}
