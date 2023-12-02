/*
** File Name: EntityManager.hpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Declaration of the EntityManager class
**
** Copyright (c) 2023 Random Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the 'Software'), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
*/

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
