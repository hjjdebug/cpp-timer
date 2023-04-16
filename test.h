#ifndef TIMER_TEST_H
#define TIMER_TEST_H
class Timer;
class TimerTest {
public:
    TimerTest();
    ~TimerTest();
    void testStart();
    void testRecycle();
    void testStop();
private:
    // 定义一个回调,注意是静态的
    static void onTimeout();
private:
    Timer* t;
};

#endif
