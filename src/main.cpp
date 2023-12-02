#include <Enemy.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>
#include <Player.hpp>
#include <Sfml.hpp>
#include <transform.h>

int main(int argc, const char **argv)
{
    IRenderer *renderer = new Sfml();
    EntityManager manager(renderer->getScaleFactor());

    manager.addEntity(std::make_unique<Player>(renderer->getScaleFactor()));
    manager.addEntity(std::make_unique<Enemy>(renderer->getScaleFactor()));

    while (renderer->windowIsOpen()) {

        renderer->handleEvents(manager);

        renderer->clear();

        manager.drawEntities(*renderer);

        renderer->render();
    }
    return 0;
}
