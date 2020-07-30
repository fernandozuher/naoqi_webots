#include "Mutex.hpp"

Mutex::Mutex() : mutex {new pthread_mutex_t}
{
    pthread_mutex_init(mutex, NULL);
}

void Mutex::lock()
{
    pthread_mutex_lock(mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(mutex);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(mutex);
    delete mutex;
}