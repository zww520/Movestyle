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
 * @brief ���ڼ�ʱ���࣬����Ӵӵ���start�����ڵ�ʱ��������λΪms
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
