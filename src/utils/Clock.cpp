#include "Clock.hpp"

Clock::Clock()
{
    _clock = clock();
}

Clock::~Clock()
{
}

double Clock::GetElapsedTime()
{
    return ((double)(clock() - _clock) / (CLOCKS_PER_SEC / 1000));
}

void Clock::Restart()
{
    _clock = clock();
}