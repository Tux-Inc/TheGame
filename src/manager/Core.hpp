#ifndef CORE_HPP_
#define CORE_HPP_

#include <SceneManager.hpp>
#include <Sfml.hpp>

class Core {
    public:
        Core();
        ~Core();
        void run();
        void gameLoop();

    protected:
    private:
        SceneManager *_sceneManager;
        IRenderer *_renderer;
};

#endif /* !CORE_HPP_ */
