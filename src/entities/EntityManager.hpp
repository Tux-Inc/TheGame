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
        void setPosition(sf::Vector2f pos, size_t entityId);
        sf::Vector2f getPosition(size_t entityId);

    private:
        std::vector<std::shared_ptr<IEntity>> _entities;
        vec2f _scaleFactor;
};

#endif /* !ENTITYMANAGER_HPP_ */
