#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>
#include <ctime>

class Clock {
    private:
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_previousTime;

    public:
        Clock()
        {
            m_startTime = std::chrono::steady_clock::now();
            m_previousTime = m_startTime;
        }

        float Tick()
        {
            auto currentTime = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - m_previousTime);
            m_previousTime = currentTime;
            return duration.count() * 100;
        }
};

#endif /* !CLOCK_HPP_ */
