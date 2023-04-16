#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <unistd.h>
#include <functional>
#include <thread>
#include <iostream>

class Timer {
public:
    Timer(unsigned seconds);
    ~Timer();
    void start(std::function<void ()> handle);
    void recycle(std::function<void ()> handle);
    void stop();

private:
    unsigned seconds = 0;
    bool isAlive = false;
};

#endif
