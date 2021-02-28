//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_DATA_H
#define MOVESTYLE_DATA_H

#include <cstdlib>
#include <cstring>
using uint8_t = unsigned char;

/**
 * @brief ���֡����
 * */
class Data {
public:
    uint8_t *ptr = nullptr;  // ָ������
    int *ref_cnt = nullptr;  // ָ�����ݵ�ָ�����
    long long  pts = 0;  // ��ʾʱ����
    int len = 0;
    int w = 0;  //֡��
    int h = 0; //֡��
    Data();
    ~Data();

    Data(const Data& obj);
    Data& operator=(Data& obj) noexcept;  // copy
    void allocate(int _w,int _h,int _len);
    void deallocate();
    void build(uint8_t* &_src,int _pts);


};


#endif //MOVESTYLE_DATA_H
