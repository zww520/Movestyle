//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_SINGLE_DATA_QUEUE_H
#define MOVESTYLE_SINGLE_DATA_QUEUE_H

#include "data.h"

const int MAX_SIZE = 60;
const int THRESHOLD = 10;
/**
 * @brief 存放帧数据的队列，单例模式
 * */
class SingleDataQueue
{
private:
    SingleDataQueue();
    ~SingleDataQueue();
    Data que[MAX_SIZE] = {};
    int top = 0;  // 队头
    int tail = 0; // 队尾
    int size = 0;
public:
    static SingleDataQueue& getInstance();
    void push(Data& _data);
    void pop();
    void reset();
    bool empty();
    bool filled();
    bool needPull();
    const Data& front();
};


#endif //MOVESTYLE_SINGLE_DATA_QUEUE_H
