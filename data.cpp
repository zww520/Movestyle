//
// Created by 18378 on 2021/2/26.
//

#include "data.h"

#include <iostream>

Data::Data()
{
    ptr = nullptr;
    ref_cnt = nullptr;
    pts = 0;
    len = 0;
    w = 0;
    h = 0;
}

Data::~Data()
{
    if(ref_cnt!= nullptr)
    {
        *ref_cnt = *ref_cnt - 1;
        if(*ref_cnt==0)
        {
            free(ptr);
            free(ref_cnt);
            ptr = nullptr;
            ref_cnt = nullptr;
        }
    }
}

/**
 * copy
 * */
Data::Data(const Data& obj)
{
    if(obj.ptr!=nullptr)
    {
        ptr = obj.ptr;
        pts = obj.pts;
        len = obj.len;
        w = obj.w;
        h = obj.h;
        ref_cnt = obj.ref_cnt;
        *ref_cnt = *ref_cnt + 1;
    }
}

/**
 * @brief copy
 * */
Data& Data::operator=(Data& obj) noexcept
{
    if(obj.ptr==nullptr)
        return *this;
    if(ptr!=nullptr)
    {
        *ref_cnt = *ref_cnt - 1;
        if (*ref_cnt == 0)
        {
            free(ptr);
            free(ref_cnt);
            ptr = nullptr;
            ref_cnt = nullptr;
        }
    }
    ptr = obj.ptr;
    pts = obj.pts;
    len = obj.len;
    w = obj.w;
    h = obj.h;
    ref_cnt = obj.ref_cnt;
    *ref_cnt = *ref_cnt + 1;
    return *this;
}

void Data::allocate(int _w,int _h,int _len)
{
    if(ptr!=nullptr) {
        *ref_cnt = *ref_cnt - 1;
        if (*ref_cnt == 0)
        {
            free(ptr);
            free(ref_cnt);
            ptr = nullptr;
            ref_cnt = nullptr;
        }
    }
    ptr = (uint8_t*)malloc(sizeof(uint8_t)*_len);
    ref_cnt = (int*)malloc(sizeof(int));
    *ref_cnt = 1;
    pts = 0;
    len =_len;
    w = _w;
    h = _h;
}

void Data::deallocate()
{
    if(ptr!=nullptr) {
        *ref_cnt = *ref_cnt - 1;
        if (*ref_cnt == 0)
        {
            free(ptr);
            free(ref_cnt);
            ptr = nullptr;
            ref_cnt = nullptr;
        }
    }
    ref_cnt = nullptr;
    ptr = nullptr;
    pts = 0;
    len = 0;
    w = 0;
    h = 0;
}

void Data::build(uint8_t *&_src, int _pts)
{
    memcpy(ptr,_src,len);
    pts = _pts;
}