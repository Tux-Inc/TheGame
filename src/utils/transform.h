#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>

sf::Vector2f getScaleFactor(uint32_t w, uint32_t h);
sf::Vector2f scaleVector(sf::Vector2f v, sf::Vector2f scaleFactor);

#endif /* !TRANSFORM_H_ */
