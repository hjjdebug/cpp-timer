#include "Timer.h"
//#pragma GCC diagnostic ignored "-Wsign-compare"
Timer::Timer(unsigned seconds) {
    this->seconds = seconds;
}

Timer::~Timer() {

}

void Timer::start(std::function<void ()> handle) 
{
    if (!this->isAlive) 
	{
        this->isAlive = true;
        auto timeThread = [=] 
		{
            for (unsigned int i = 0; i< (this->seconds * 1000); i++) 
			{
                if (this->isAlive) 
				{
                    usleep(1000);
                } 
				else 
				{
                    return;
                }
            }

            if (this->isAlive) 
			{
                handle();
            }
            this->stop();
            return;
        };

        std::thread t(timeThread);
        t.detach();
    }
}

void Timer::recycle(std::function<void ()> handle) {
    if (!this->isAlive) {
        this->isAlive = true;

        auto timeThread = [=] 
		{
            while (this->isAlive) 
			{
                for (unsigned int i = 0; i < (this->seconds * 1000); i++) 
				{
                    if (this->isAlive) 
					{
                        usleep(1000);
                    } 
					else 
					{
                        return;
                    }
                }
                if (this->isAlive) 
				{
                    handle();
                }
            }
        };

        std::thread t(timeThread);
        t.detach();
    }
}

void Timer::stop() {
    this->isAlive = false;
}
