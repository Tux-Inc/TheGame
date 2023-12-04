#ifndef ISOUND_HPP_
#define ISOUND_HPP_

class Scene;
class EntityManager;

class ISound {
    public:
        virtual void init() = 0;
        virtual void init(std::string path) = 0;
        virtual void clear() = 0;
        virtual void play(const sf::Drawable &drawable) = 0;
        virtual void render() = 0;
        virtual void handleEvents(std::shared_ptr<Scene> scene, size_t &currentScene) = 0;
        virtual ~ISound() = default;
};

#endif /* !ISOUND_HPP_ */
