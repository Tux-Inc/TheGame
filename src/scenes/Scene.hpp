#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <Clock.hpp>
#include <MusicManager.hpp>
#include <SoundManager.hpp>
#include <EntityManager.hpp>

class IRenderer;
class MusicManager;
class SoundManager;
class EntityManager;

class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = 0;
        virtual void updateScene(float dt, size_t &currentScene) = 0;
        virtual void drawScene(IRenderer &renderer) = 0;
        virtual void handleEvents(sf::Event event, size_t &currentScene) = 0;

    protected:
        EntityManager *_manager;
        MusicManager *_musicManager;
        SoundManager *_soundManager;
        sf::Vector2f _scaleFactor;
        int *_currentScene;
};

#endif /* !SCENE_HPP_ */
