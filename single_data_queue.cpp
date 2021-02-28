//
// Created by 18378 on 2021/2/26.
//

#include "single_data_queue.h"

#include <QDebug>

SingleDataQueue::SingleDataQueue()
{
    top = 0;
    tail = 0;
    size = 0;
}

SingleDataQueue::~SingleDataQueue()
{

}

SingleDataQueue & SingleDataQueue::getInstance()
{
    static SingleDataQueue singleDataQueue;
    return singleDataQueue;
}

void SingleDataQueue::push(Data &_data)
{
    if(filled())
        return;
    que[tail] = _data;
    tail = (tail+1)%MAX_SIZE;
    size++;
}

void SingleDataQueue::pop()
{
    if(empty())
        return;
    top = (top+1)%MAX_SIZE;
    size--;
}

void SingleDataQueue::reset()
{
    size = 0;
    top = tail = 0;
    for(int i=0;i<MAX_SIZE;i++)
        que[i].deallocate();
    qDebug()<<"reset\n";
}

const Data& SingleDataQueue::front()
{
    return que[top];
}

bool SingleDataQueue::filled()
{
    return size==MAX_SIZE;
}

bool SingleDataQueue::empty()
{
    return size==0;
}

bool SingleDataQueue::needPull()
{
    return size < THRESHOLD;
}

