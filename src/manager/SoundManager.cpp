#include <SoundManager.hpp>

SoundManager::SoundManager(float volume)
{
    _volume = volume;
}

SoundManager::~SoundManager()
{
}

void SoundManager::addSound(std::shared_ptr<ISound> sound)
{
    _sounds.push_back(sound);
}

void SoundManager::playSounds()
{
    for (size_t i = 0; i < _sounds.size(); i++) {
        _sounds[i]->play(0);
    }
}

std::shared_ptr<ISound> SoundManager::getSound(size_t soundId)
{
    return _sounds[soundId];
}

std::vector<std::shared_ptr<ISound>> SoundManager::getSounds()
{
    return _sounds;
}

size_t SoundManager::getSoundsSize() const
{
    return _sounds.size();
}
