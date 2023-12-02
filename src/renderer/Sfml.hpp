/*
** File Name: Sfml.hpp
** Author: Lionel Da Rocha Da Silva, Julien Augugliaro, Raphaël Launay,
**         Olivier Pouech et Alexandre De Freitas Martins
** Creation Date: 2023
** Description: Implementation of the Sfml class methods
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

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include <Renderer.hpp>
    #include <SFML/Graphics.hpp>
    #include <transform.h>

class IRenderer;

class Sfml : public Renderer {
    public:
        Sfml();
        ~Sfml() override;
        void init() override;
        void clear() override;
        void draw(const sf::Drawable &drawable) override;
        void render() override;
        void handleEvents(EntityManager &manager) override;
        bool windowIsOpen() const override;
        vec2f getScaleFactor() const override;

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        vec2f _scaleFactor;
        uint32_t _w;
        uint32_t _h;
};

#endif /* !SFML_HPP_ */
