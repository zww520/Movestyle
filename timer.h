//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_TIMER_H
#define MOVESTYLE_TIMER_H

#include <chrono>

using std::chrono::steady_clock;
using std::chrono::milliseconds;
using T = long long;

/**
 * @brief 用于计时的类，计算从从调用start到现在的时间间隔，单位为ms
 * */
class Timer
{
private:
    T now = 0;
    bool runnig = false;
    decltype(steady_clock::now()) orign;
public:
    explicit Timer();
    Timer(const Timer &obj) = delete;
    ~Timer();
    void start();
    void stop();
    void reset();
    void resume();
    T getTime();
};


#endif //MOVESTYLE_TIMER_H
