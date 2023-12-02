/*
** File Name: Entity.hpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Declaration of the Entity class
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

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <IEntity.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <memory>
    #include <vector>

class Entity : public IEntity {
    public:
        Entity() = default;
        ~Entity();
        virtual void update(float dt) = 0;
        void draw(IRenderer &renderer) override;
        void setPosition(sf::Vector2f pos) override;
        sf::Vector2f getPosition() const override;

    protected:
        sf::Drawable *_drawable;
        sf::Transformable *_transformable;
        vec2f _scaleFactor;
        sf::Vector2f _pos;

    private:
};

#endif /* !ENTITY_HPP_ */
