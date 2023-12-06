#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <IEntity.hpp>
#include <IRenderer.hpp>
#include <iostream>
#include <memory>
#include <transform.h>
#include <vector>

class IEntity;
class IRenderer;

class EntityManager {
    public:
        EntityManager(vec2f scale);
        ~EntityManager();
        void addEntity(std::shared_ptr<IEntity> entity);
        void updateEntities(float dt);
        void drawEntities(IRenderer &renderer);
        void handleEvents(const sf::Event &event);
        std::shared_ptr<IEntity> getEntity(size_t entityId);
        std::vector<std::shared_ptr<IEntity>> getEntities();
        size_t getEntitiesSize() const;
        Direction collision(std::shared_ptr<IEntity> e1, std::shared_ptr<IEntity> e2);
        void action(size_t entityId, ActionType action, Direction direction, const std::string &text);

    private:
        std::vector<std::shared_ptr<IEntity>> _entities;
        vec2f _scaleFactor;
};

#endif /* !ENTITYMANAGER_HPP_ */
