#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <ISound.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Sound : public ISound {
    public:
        Sound();
        ~Sound();
        void init();
        void clear();
        void play(const sf::Drawable &drawable);
        void render();
        void handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene);

    protected:
       std::vector<sf::Sound> _sounds;
       std::vector<sf::SoundBuffer> _buffers;
};

#endif /* !SOUND_HPP_ */
