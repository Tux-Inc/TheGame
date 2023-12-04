#include "Sound.hpp"

Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::init()
{
    if (!_buffer.loadFromFile("./assets/sound/coin.wav"))
        std::cerr << "Error loading sound" << std::endl;
    _sound.setBuffer(_buffer);
}

void Sound::clear()
{
}

void Sound::play(const sf::Drawable &drawable)
{
    if (_sound.getStatus() != sf::Sound::Playing)
        _sound.play();
}

void Sound::render()
{
}

void Sound::handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene)
{
}
