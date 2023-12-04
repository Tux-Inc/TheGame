#ifndef MUSICMANAGER_HPP_
#define MUSICMANAGER_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <IMusic.hpp>
#include <transform.h>
#include <IRenderer.hpp>

class IMusic;
class IRenderer;

class MusicManager {
    public:
        MusicManager(float volume);
        ~MusicManager();
        void addMusic(std::shared_ptr<IMusic> music);
        void playMusics();
        std::shared_ptr<IMusic> getMusic(size_t musicId);
        std::vector<std::shared_ptr<IMusic>> getMusics();
        size_t getMusicsSize() const;

    private:
        float _volume;
        std::vector<std::shared_ptr<IMusic>> _musics;
};

#endif /* !MUSICMANAGER_HPP_ */
