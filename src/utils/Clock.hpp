#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <ctime>

class Clock {
    public:
        Clock();
        ~Clock();
        double GetElapsedTime();
        void Restart();

    protected:
    private:
        clock_t _clock;
};

#endif /* !CLOCK_HPP_ */
