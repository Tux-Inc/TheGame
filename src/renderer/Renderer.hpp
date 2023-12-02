/*
** File Name: Renderer.hpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Interface for all renderers
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

#ifndef RENDERER_HPP_
    #define RENDERER_HPP_

    #include <IRenderer.hpp>

class IRenderer;
class Renderer : public IRenderer {
    public:
        Renderer() = default;
        ~Renderer();
        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void draw(const sf::Drawable &drawable) = 0;
        virtual void render() = 0;
        virtual void handleEvents(EntityManager &manager) = 0;
        virtual bool windowIsOpen() const = 0;
        virtual vec2f getScaleFactor() const = 0;
};

#endif /* !RENDERER_HPP_ */
