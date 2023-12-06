#ifndef ISOUND_HPP_
#define ISOUND_HPP_

class Scene;
class EntityManager;

class ISound {
    public:
        enum class MySoundState {
            PLAYING,
            PAUSED,
            STOPPED
        };
        virtual ~ISound() = default;
        virtual void play(size_t assetId) = 0;
        virtual void stop(size_t assetId) = 0;
        virtual void pause(size_t assetId) = 0;
        virtual void changePitch(size_t assetId, float pitch) = 0;
        virtual void changeVolume(size_t assetId, float volume) = 0;
        virtual void changeMinDistance(size_t assetId, float distance) = 0;
        virtual void changeAttenuation(size_t assetId, float attenuation) = 0;
        virtual void changeRelativeToListener(size_t assetId, bool relative) = 0;
        virtual void changePosition(size_t assetId, float x, float y, float z) = 0;
        virtual MySoundState getStatus(size_t assetId) const = 0;
};

#endif /* !ISOUND_HPP_ */
