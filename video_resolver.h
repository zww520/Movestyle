//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_VIDEO_RESOLVER_H
#define MOVESTYLE_VIDEO_RESOLVER_H

#include "resolver.h"
#include "timer.h"
#include "single_data_queue.h"
#include "ffmpeger.h"

#include <thread>

/**
 * @brief  ”∆µΩ‚Œˆ¿‡
 * */
class VideoResolver : public Resolver
{
private:
    std::thread* consumer = nullptr;
    std::thread* producer = nullptr;
    bool exited = true;
    bool running = false;
    int w = 0;
    int h = 0;
    Timer timer;
    FFmpeger ffmpeger;
public:
    VideoResolver();
    ~VideoResolver() override;

    void produce();
    void consume();

    void start() override;
    void stop() override;
    void exit() override;
    virtual bool init(QString _url) override;
};


#endif //MOVESTYLE_VIDEO_RESOLVER_H
