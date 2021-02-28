//
// Created by 18378 on 2021/2/26.
//

#include "ffmpeger.h"

FFmpeger::FFmpeger()
{

}

FFmpeger::~FFmpeger()
{

}

bool FFmpeger::init(const char *url)
{
    int ret = 1;
    try {
        ret = avformat_open_input(&ctx,url, nullptr, nullptr);
        if(ret!=0) {
            throw -1;
        }
    }
    catch (int){
        return false;
    }
    for(int i=0;i<ctx->nb_streams;i++) {
        if(ctx->streams[i]->codecpar->codec_type==AVMEDIA_TYPE_VIDEO) {
            index = i;
            w = ctx->streams[i]->codecpar->width;
            h = ctx->streams[i]->codecpar->height;
            long long num = ctx->streams[i]->time_base.num;
            long long den = ctx->streams[i]->time_base.den;
            time_unit = den/num/1000;
            break;
        }
    }
    if(index==-1 || time_unit==0)
    {
        return false;
    }
    if(ctx->streams[index]->codecpar->codec_id==AV_CODEC_ID_FIRST_UNKNOWN)
    {
        return false;
    }
    codec = avcodec_find_decoder(ctx->streams[index]->codecpar->codec_id);
    codeCtx = avcodec_alloc_context3(codec);
    frame = av_frame_alloc();
    pkt = av_packet_alloc();
    avcodec_parameters_to_context(codeCtx,ctx->streams[index]->codecpar);
    avcodec_open2(codeCtx,codec,nullptr);
    swsCtx = sws_getContext(w,h,AV_PIX_FMT_YUV420P,w,h,
                            AV_PIX_FMT_RGB24, SWS_BILINEAR, nullptr, nullptr, nullptr);
    for(int i=0;i<DATA_POINTERS_NUM;i++)
    {
        stride[i] = w*3;
        data[i] = (uint8_t*)malloc(sizeof(uint8_t)*w*h*3);
    }
    return true;
}

/**
 * @brief 返回下一帧数据
 * @var res 存放帧，需提前申请内存,且res.w = w, res.h = h
 * */
void FFmpeger::next(Data& res)
{
    bool flag = false;
    while(!flag)
    {
        int ret = av_read_frame(ctx,pkt);
        if(ret==AVERROR_EOF)
        {
            av_seek_frame(ctx, index, 0, AVSEEK_FLAG_BACKWARD); //AVSEEK_FLAG_BACKWARD
            av_packet_unref(pkt);
            continue;
        }
        if(pkt->stream_index==index)
        {
            avcodec_send_packet(codeCtx,pkt);
            avcodec_receive_frame(codeCtx,frame);
            if(frame->width>0)
            {
                sws_scale(swsCtx,frame->data,frame->linesize,0,h,
                          data,stride);
                int pts = frame->pts / time_unit;
                if(pts<=pre_pts)
                {
                    res.build(data[0],-1);
                    pre_pts = -1;
                }
                else
                {
                    pre_pts = pts;
                    res.build(data[0],pts);
                }
                flag = true;
            }
            av_frame_unref(frame);
        }
        av_packet_unref(pkt);
    }
    return;
}