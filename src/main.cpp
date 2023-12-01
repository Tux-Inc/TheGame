#include <Enemy.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>
#include <Player.hpp>
#include <Sfml.hpp>
#include <transform.h>

int main(int argc, const char** argv)
{
    EntityManager manager;
    IRenderer* renderer = new Sfml();

    manager.addEntity(std::make_unique<Player>());
    manager.addEntity(std::make_unique<Enemy>());

    while (renderer->windowIsOpen()) {

        renderer->handleEvents();

        renderer->clear();

        manager.drawEntities(*renderer);

        renderer->render();
    }
    return 0;
}