#include "MySound.hpp"

MySound::MySound()
{
    _state.push_back(MySoundState::STOPPED);
    sf::Sound *mysound = new sf::Sound();
    sf::SoundBuffer *buffer = new sf::SoundBuffer();
    if (!buffer->loadFromFile("./assets/sound/mysound.ogg"))
        std::cerr << "Error loading mysound" << std::endl;
    _mysounds.push_back(mysound);
    _buffers.push_back(buffer);
    _mysounds[0]->setBuffer(*buffer);
    _mysounds[0]->setVolume(50.0f);
    // _mysounds[0]->setLoop(true);
    // _mysounds[0]->play();
}

MySound::MySound(std::string path, float volume)
{
    _state.push_back(MySoundState::STOPPED);
    sf::Sound *mysound = new sf::Sound();
    sf::SoundBuffer *buffer = new sf::SoundBuffer();
    if (!buffer->loadFromFile(path))
        std::cerr << "Error loading sound from " << path << std::endl;
    _mysounds.push_back(mysound);
    _buffers.push_back(buffer);
    _mysounds[0]->setBuffer(*buffer);
    _mysounds[0]->setVolume(volume);
    // _mysounds[0]->setLoop(true);
    // _mysounds[0]->play();
}

MySound::~MySound()
{
}

void MySound::play(size_t assetId)
{
    _state[assetId] = MySoundState::PLAYING;
    if (_mysounds[assetId]->getStatus() != sf::Sound::Playing && _state[assetId] == MySoundState::PLAYING) {
        _mysounds[assetId]->play();
    }
    _state[assetId] = MySoundState::STOPPED;
}

void MySound::stop(size_t assetId)
{
    _state[assetId] = MySoundState::STOPPED;
    if (_mysounds[assetId]->getStatus() != sf::Sound::Stopped && _state[assetId] == MySoundState::STOPPED) {
        _mysounds[assetId]->stop();
    }
    _state[assetId] = MySoundState::PLAYING;
}

void MySound::pause(size_t assetId)
{
    _state[assetId] = MySoundState::PAUSED;
    if (_mysounds[assetId]->getStatus() != sf::Sound::Paused && _state[assetId] == MySoundState::PAUSED) {
        _mysounds[assetId]->pause();
    }
    _state[assetId] = MySoundState::STOPPED;
}

void MySound::changePitch(size_t assetId, float pitch)
{
    _mysounds[assetId]->setPitch(pitch);
}

void MySound::changeVolume(size_t assetId, float volume)
{
    _mysounds[assetId]->setVolume(volume);
}

void MySound::changeMinDistance(size_t assetId, float distance)
{
    _mysounds[assetId]->setMinDistance(distance);
}

void MySound::changeAttenuation(size_t assetId, float attenuation)
{
    _mysounds[assetId]->setAttenuation(attenuation);
}

void MySound::changeRelativeToListener(size_t assetId, bool relative)
{
    _mysounds[assetId]->setRelativeToListener(relative);
}

void MySound::changePosition(size_t assetId, float x, float y, float z)
{
    _mysounds[assetId]->setPosition(x, y, z);
}

MySound::MySoundState MySound::getStatus(size_t assetId) const
{
    return _state[assetId];
}
