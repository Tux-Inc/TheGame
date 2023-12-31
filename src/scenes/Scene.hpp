#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <Clock.hpp>
#include <EntityManager.hpp>
#include <MusicManager.hpp>
#include <SoundManager.hpp>

class IRenderer;
class MusicManager;
class SoundManager;
class EntityManager;

class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = 0;
        virtual void updateScene(float dt, size_t &currentScene, size_t &previousScene) = 0;
        virtual void drawScene(IRenderer &renderer) = 0;
        virtual void handleEvents(sf::Event event, size_t &currentScene, size_t &previousScene) = 0;
        void resetScene();

    protected:
        EntityManager *_manager;
        MusicManager *_musicManager;
        SoundManager *_soundManager;
        sf::Vector2f _scaleFactor;
        int *_currentScene;
        std::chrono::steady_clock::time_point _start;
        std::chrono::steady_clock::time_point _end;
        std::chrono::steady_clock::time_point _nextTime;
        bool _active;
        int _elapsedTime;
};

#endif /* !SCENE_HPP_ */
