#ifndef SOUNDMANAGER_HPP_
#define SOUNDMANAGER_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <ISound.hpp>
#include <transform.h>
#include <IRenderer.hpp>

class ISound;
class IRenderer;

class SoundManager {
    public:
        SoundManager(float volume);
        ~SoundManager();
        void addSound(std::shared_ptr<ISound> sound);
        void playSounds();
        std::shared_ptr<ISound> getSound(size_t soundId);
        std::vector<std::shared_ptr<ISound>> getSounds();
        size_t getSoundsSize() const;

    private:
        float _volume;
        std::vector<std::shared_ptr<ISound>> _sounds;
};

#endif /* !SOUNDMANAGER_HPP_ */
