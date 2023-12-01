/*
** EPITECH PROJECT, 2023
** jam
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <IRenderer.hpp>
#include <SFML/Graphics.hpp>

class Sfml: public IRenderer {
    public:
        Sfml();
        ~Sfml();
        void init() override;
        void clear() override;
        void draw(const sf::Drawable& drawable) override;
        void render() override;
        void handleEvents() override;
        bool windowIsOpen() const override;
    private:
        sf::RenderWindow _window;
        sf::Event _event;
};

#endif /* !SFML_HPP_ */
