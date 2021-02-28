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
 * @brief ��ʼ��ʱ,ֻ����һ��
 * */
void Timer::start()
{
    runnig = true;
    now = 0;
    orign = steady_clock::now();
}

/**
 * @brief ��ͣ��ʱ
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
 * @brief �ָ���ʱ
 * */
void Timer::resume()
{
    if(runnig==true)
        return;
    runnig = true;
    orign = steady_clock::now();
}

/**
 * @brief ��֮ǰ��ʱ��������Ϊ0
 * */
void Timer::reset()
{
    now = 0;
    orign = steady_clock::now();
}

/**
 * @brief ��ȡʱ����
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