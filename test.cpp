#include "test.h"
#include "Timer.h"
TimerTest::TimerTest() {
    this->t = nullptr;
}

TimerTest::~TimerTest() {
    delete this->t;
    this->t = nullptr;
}

void TimerTest::testStart() {
    if (this->t == nullptr) {
        this->t = new Timer(10); // new一个10秒延时的定时器出来
    }
    this->t->start(onTimeout); // 传入回调，10秒后执行回调一次，任务结束
}

void TimerTest::testRecycle() {
    if (this->t == nullptr) {
        this->t = new Timer(1);
    }
    this->t->recycle(onTimeout); // 传入回调，循环定时，每10秒执行一次回调
}

void TimerTest::testStop() {
    if (this->t == nullptr) {
        this->t = new Timer(10);
    }   
    this->t->start(onTimeout);
    this->t->stop(); // 停掉前面的start

    this->t->recycle(onTimeout);
    this->t->stop(); // 停掉前面的recycle
}

void TimerTest::onTimeout()
{
    std::cout << "timer run" << std::endl;
}
int main()
{
	TimerTest t;
	t.testRecycle();
	while(1)
	{
		sleep(1);
	}
}
