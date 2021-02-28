//
// Created by 18378 on 2021/2/26.
//

#include "video_resolver.h"
#include "error.h"

#include <QDebug>

VideoResolver::VideoResolver()
{

}

VideoResolver::~VideoResolver() noexcept
{
    exit();
}

void VideoResolver::produce()
{
    SingleDataQueue& que = SingleDataQueue::getInstance();
    while(!exited)
    {
        while(running)
        {
            while(!que.filled())
            {
                Data tmp_frame;
                tmp_frame.allocate(w,h,w*h*3);
                ffmpeger.next(tmp_frame);
                que.push(tmp_frame);
            }
            std::this_thread::sleep_for(milliseconds(500));
        }
        std::this_thread::sleep_for(milliseconds(1));
    }
    que.reset();
}

void VideoResolver::consume()
{
    SingleDataQueue& que = SingleDataQueue::getInstance();
    while(!exited)
    {
        while(running)
        {
            if(!que.empty())
            {
                const Data& frame = que.front();
                if(frame.pts==-1)
                {
                    timer.reset();
                    que.pop();
                }
                else if(frame.pts<=timer.getTime())
                {
                    emit signals_ready_refresh();
                }
            }
            std::this_thread::sleep_for(milliseconds(10));
        }
        std::this_thread::sleep_for(milliseconds(1));
    }
}

void VideoResolver::start()
{
    running = true;
    timer.resume();
}

void VideoResolver::stop()
{
    running = false;
    timer.stop();
}

void VideoResolver::exit()
{
    running = false;
    exited = true;
    if(producer!=nullptr)
        producer->join();
    if(consumer!=nullptr)
        consumer->join();
    producer = nullptr;
    consumer = nullptr;
}

bool VideoResolver::init(QString _url)
{
    exit();
    running = true;
    exited = false;
    bool res = ffmpeger.init(_url.toStdString().data());
    if(!res)
    {
        setLastError(RESOLVER_ERROR);
        emit signals_internal_error();
        return false;
    }
    w = ffmpeger.w;
    h = ffmpeger.h;
    timer.start();
    producer = new std::thread(&VideoResolver::produce,this);
    consumer = new std::thread(&VideoResolver::consume,this);
    return true;
}
