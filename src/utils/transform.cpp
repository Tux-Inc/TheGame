#include <transform.h>

sf::Vector2f scaleVector(sf::Vector2f v, vec2f scaleFactor) {
    
    sf::Vector2f scaled;
    scaled.x = v.x * scaleFactor.x;
    scaled.y = v.y * scaleFactor.y;
    return scaled;
}