#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <IMusic.hpp>

class MyMusic : public IMusic {
    public:
        MyMusic();
        MyMusic(std::string path, float volume);
        ~MyMusic();
        void play(size_t assetId) override;
        void stop(size_t assetId) override;
        void pause(size_t assetId) override;
        void changePitch(size_t assetId, float pitch) override;
        void changeVolume(size_t assetId, float volume) override;
        void changeMinDistance(size_t assetId, float distance) override;
        void changeAttenuation(size_t assetId, float attenuation) override;
        void changeRelativeToListener(size_t assetId, bool relative) override;
        void changePosition(size_t assetId, float x, float y, float z) override;
        MyMusicState getStatus(size_t assetId) const;

    protected:
       std::vector<sf::Music *> _music;
       std::vector<MyMusicState> _state;
};

#endif /* !SOUND_HPP_ */
