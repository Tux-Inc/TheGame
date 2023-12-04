#include "MyMusic.hpp"

MyMusic::MyMusic()
{
    _state.push_back(MyMusicState::STOPPED);
    sf::Music *music = new sf::Music();
    if (!music->openFromFile("./assets/music/megalovania.ogg"))
        std::cerr << "Error loading music from ./assets/music/megalovania.ogg" << std::endl;
    _music.push_back(music);
    _music[0]->setVolume(50.0f);
    _music[0]->setLoop(true);
    _music[0]->play();
}

MyMusic::MyMusic(std::string path, float volume)
{
    _state.push_back(MyMusicState::STOPPED);
    sf::Music *music = new sf::Music();
    if (!music->openFromFile(path))
        std::cerr << "Error loading music from " << path << std::endl;
    _music.push_back(music);
    _music[0]->setVolume(volume);
    _music[0]->setLoop(true);
    _music[0]->play();
}

MyMusic::~MyMusic()
{
}

void MyMusic::play(size_t assetId)
{
    if (_music[assetId]->getStatus() != sf::SoundSource::Status::Playing && _state[assetId] == MyMusicState::PLAYING) {
        _music[assetId]->play();
        _state[assetId] = MyMusicState::PLAYING;
    }
}

void MyMusic::stop(size_t assetId)
{
    if (_music[assetId]->getStatus() != sf::SoundSource::Status::Stopped && _state[assetId] == MyMusicState::STOPPED) {
        _music[assetId]->stop();
        _state[assetId] = MyMusicState::STOPPED;
    }
}

void MyMusic::pause(size_t assetId)
{
    if (_music[assetId]->getStatus() != sf::SoundSource::Status::Paused && _state[assetId] == MyMusicState::PAUSED) {
        _music[assetId]->pause();
        _state[assetId] = MyMusicState::PAUSED;
    }
}

void MyMusic::changePitch(size_t assetId, float pitch)
{
    _music[assetId]->setPitch(pitch);
}

void MyMusic::changeVolume(size_t assetId, float volume)
{
    _music[assetId]->setVolume(volume);
}

void MyMusic::changeMinDistance(size_t assetId, float distance)
{
    _music[assetId]->setMinDistance(distance);
}

void MyMusic::changeAttenuation(size_t assetId, float attenuation)
{
    _music[assetId]->setAttenuation(attenuation);
}

void MyMusic::changeRelativeToListener(size_t assetId, bool relative)
{
    _music[assetId]->setRelativeToListener(relative);
}

void MyMusic::changePosition(size_t assetId, float x, float y, float z)
{
    _music[assetId]->setPosition(x, y, z);
}

MyMusic::MyMusicState MyMusic::getStatus(size_t assetId) const
{
    return _state[assetId];
}
