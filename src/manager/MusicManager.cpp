#include <MusicManager.hpp>

MusicManager::MusicManager(float volume)
{
    _volume = volume;
}

MusicManager::~MusicManager()
{
}

void MusicManager::addMusic(std::shared_ptr<IMusic> music)
{
    _musics.push_back(music);
}

void MusicManager::playMusics()
{
    for (size_t i = 0; i < _musics.size(); i++) {
        _musics[i]->play(0);
    }
}

std::shared_ptr<IMusic> MusicManager::getMusic(size_t musicId)
{
    return _musics[musicId];
}

std::vector<std::shared_ptr<IMusic>> MusicManager::getMusics()
{
    return _musics;
}

size_t MusicManager::getMusicsSize() const
{
    return _musics.size();
}
