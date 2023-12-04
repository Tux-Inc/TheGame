#ifndef IMUSIC_HPP_
#define IMUSIC_HPP_

#include <SFML/Audio.hpp>

class Scene;
class EntityManager;

class IMusic {
    public:
        virtual void play(size_t assetId) = 0;
        virtual void stop(size_t assetId) = 0;
        virtual void pause(size_t assetId) = 0;
        virtual void resume(size_t assetId) = 0;
        virtual void changePitch(size_t assetId, float pitch) = 0;
        virtual void changeVolume(size_t assetId, float volume) = 0;
        virtual void changeMinDistance(size_t assetId, float distance) = 0;
        virtual void changeAttenuation(size_t assetId, float attenuation) = 0;
        virtual void changeRelativeToListener(size_t assetId, bool relative) = 0;
        virtual void changePosition(size_t assetId, float x, float y, float z) = 0;
        virtual ~IMusic() = default;
};

#endif /* !IMUSIC_HPP_ */
