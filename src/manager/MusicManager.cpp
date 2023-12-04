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
