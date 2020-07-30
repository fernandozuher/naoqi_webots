// Description: Class helping to measure delta time in milliseconds

#ifndef TIMER_HPP
#define TIMER_HPP

// C library
#include <cstdlib>
// Unix systems library
#include <sys/time.h>

class Timer
{
    private:
        double __time() const; // second
        double before_time;

    public:
        Timer();
        virtual ~Timer();

        double delta(); // second
        void reset();
};

#endif