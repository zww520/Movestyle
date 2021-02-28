//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_DATA_H
#define MOVESTYLE_DATA_H

#include <cstdlib>
#include <cstring>
using uint8_t = unsigned char;

/**
 * @brief 存放帧数据
 * */
class Data {
public:
    uint8_t *ptr = nullptr;  // 指向数据
    int *ref_cnt = nullptr;  // 指向数据的指针个数
    long long  pts = 0;  // 显示时间龊
    int len = 0;
    int w = 0;  //帧高
    int h = 0; //帧宽
    Data();
    ~Data();

    Data(const Data& obj);
    Data& operator=(Data& obj) noexcept;  // copy
    void allocate(int _w,int _h,int _len);
    void deallocate();
    void build(uint8_t* &_src,int _pts);


};


#endif //MOVESTYLE_DATA_H
