//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_FFMPEGER_H
#define MOVESTYLE_FFMPEGER_H

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
};

#include "data.h"

#include <iostream>

const int DATA_POINTERS_NUM = 3;

/**
 * @brief ����ffmpeg��ȡ��Ƶ��
 * */
class FFmpeger
{
private:
    AVFormatContext* ctx = nullptr;
    AVCodecContext* codeCtx = nullptr;
    AVCodec* codec = nullptr;
    AVPacket* pkt = nullptr;
    AVFrame* frame = nullptr;
    SwsContext* swsCtx = nullptr;
    int index = -1;  //��Ƶ���±�
    long long time_unit = 1; // ʱ���
    long long pre_pts = -1;
    uint8_t *data[DATA_POINTERS_NUM] = {};
    int stride[DATA_POINTERS_NUM] = {};
public:
    int w = 0;  //
    int h = 0;  //

    FFmpeger();
    ~FFmpeger();

    bool init(const char* url); // ��ʼ��FFmpeger
    void next(Data& res);
};


#endif //MOVESTYLE_FFMPEGER_H
