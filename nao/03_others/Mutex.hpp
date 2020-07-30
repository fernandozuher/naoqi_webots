// Description: Class that implements a platform independent mutex

#ifndef MUTEX_HPP
#define MUTEX_HPP

// C library
#include <cstdlib>
// Unix systems library
#include <pthread.h>

class Mutex
{
    private:
        pthread_mutex_t *mutex;
    
    public:
        Mutex();
        virtual ~Mutex();
        
        void lock();
        void unlock();
};

#endif