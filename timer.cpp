//
// Created by 18378 on 2021/2/26.
//

#include "timer.h"

Timer::Timer()
{

}

Timer::~Timer()
{
    runnig = false;
}


/**
 * @brief 开始计时,只调用一次
 * */
void Timer::start()
{
    runnig = true;
    now = 0;
    orign = steady_clock::now();
}

/**
 * @brief 暂停计时
 * */
void Timer::stop()
{
    if(runnig= false)
        return;
    auto ed = steady_clock::now();
    T dif = std::chrono::duration_cast<milliseconds>(ed-orign).count();
    now = now + dif;
    runnig = false;
}

/**
 * @brief 恢复计时
 * */
void Timer::resume()
{
    if(runnig==true)
        return;
    runnig = true;
    orign = steady_clock::now();
}

/**
 * @brief 将之前的时间间隔设置为0
 * */
void Timer::reset()
{
    now = 0;
    orign = steady_clock::now();
}

/**
 * @brief 获取时间间隔
 * */
T Timer::getTime()
{
    if(runnig)
    {
        auto ed = steady_clock::now();
        T dif = std::chrono::duration_cast<milliseconds>(ed-orign).count();
        dif = now + dif;
        return dif;
    }
    else
        return now;
}