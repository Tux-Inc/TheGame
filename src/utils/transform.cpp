#include <transform.h>


sf::Vector2f getScaleFactor(uint32_t w, uint32_t h)
{
    sf::Vector2f scale;
    const float defaultWidth = 1920.0f;
    const float defaultHeight = 1080.0f;
    scale.x = static_cast<float>(w) / defaultWidth;
    scale.y = static_cast<float>(h) / defaultHeight;
    return scale;
}

sf::Vector2f scaleVector(sf::Vector2f v, sf::Vector2f scaleFactor) {
    
    sf::Vector2f scaled;
    scaled.x = v.x * scaleFactor.x;
    scaled.y = v.y * scaleFactor.y;   
    return scaled;
}