#include "Timer.hpp"

Timer::Timer()
{
    reset();
}

double Timer::delta()
{
    return __time() - before_time;
}

void Timer::reset()
{
    before_time = __time();
}

double Timer::__time() const
{
    timeval time;
    gettimeofday(&time, NULL);
    long millis {(time.tv_sec * 1000) + (time.tv_usec / 1000)};
    return static_cast<double>(millis) / 1000.0;
}

Timer::~Timer() {}