#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <IEntity.hpp>
#include <IRenderer.hpp>
#include <iostream>
#include <memory>
#include <vector>

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void addEntity(std::shared_ptr<IEntity> entity);
        void updateEntities(float dt);
        void drawEntities(IRenderer &renderer);

    private:
        std::vector<std::shared_ptr<IEntity>> _entities;
};

#endif /* !ENTITYMANAGER_HPP_ */