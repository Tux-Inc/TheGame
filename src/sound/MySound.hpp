#ifndef MYSOUND_HPP_
#define MYSOUND_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <ISound.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MySound : public ISound {
    public:
        MySound();
        MySound(std::string path, float volume);
        ~MySound();
        void play(size_t assetId) override;
        void stop(size_t assetId) override;
        void pause(size_t assetId) override;
        void changePitch(size_t assetId, float pitch) override;
        void changeVolume(size_t assetId, float volume) override;
        void changeMinDistance(size_t assetId, float distance) override;
        void changeAttenuation(size_t assetId, float attenuation) override;
        void changeRelativeToListener(size_t assetId, bool relative) override;
        void changePosition(size_t assetId, float x, float y, float z) override;
        MySoundState getStatus(size_t assetId) const override;
    protected:
        std::vector<MySoundState> _state;
        std::vector<sf::Sound *> _mysounds;
        std::vector<sf::SoundBuffer *> _buffers;

};

#endif /* !MYSOUND_HPP_ */
