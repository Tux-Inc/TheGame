/*
** File Name: EntityManager.cpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Implementation of the EntityManager class methods
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

#include <EntityManager.hpp>

EntityManager::EntityManager(vec2f scale)
{
    _scaleFactor = scale;
}

EntityManager::~EntityManager()
{
}

void EntityManager::addEntity(std::shared_ptr<IEntity> entity)
{
    _entities.push_back(entity);
}

void EntityManager::updateEntities(float dt)
{
    for (size_t i = 0; i < _entities.size(); i++) {
        _entities[i]->update(dt);
    }
}

void EntityManager::drawEntities(IRenderer &renderer)
{
    for (size_t i = 0; i < _entities.size(); i++) {
        _entities[i]->draw(renderer);
    }
}

void EntityManager::handleEvents(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            sf::Vector2f pos = getPosition(0);
            pos.x -= 10 * _scaleFactor.x;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Right) {
            sf::Vector2f pos = getPosition(0);
            pos.x += 10 * _scaleFactor.x;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Up) {
            sf::Vector2f pos = getPosition(0);
            pos.y -= 10 * _scaleFactor.y;
            setPosition(pos, 0);
        }
        if (event.key.code == sf::Keyboard::Down) {
            sf::Vector2f pos = getPosition(0);
            pos.y += 10 * _scaleFactor.y;
            setPosition(pos, 0);
        }
    }
}

sf::Vector2f EntityManager::getPosition(size_t entityId)
{
    sf::Vector2f pos = _entities[entityId]->getPosition();
    return pos;
}

void EntityManager::setPosition(sf::Vector2f pos, size_t entityId)
{
    _entities[entityId]->setPosition(pos);
}
