//
// Created by 18378 on 2021/2/27.
//

#ifndef MOVESTYLE_UTILS_H
#define MOVESTYLE_UTILS_H

#include <windows.h>

/**
 * @brief 创建窗口
 * */
bool createHostWindow();

/**
 * @brief 判断窗口是否存在
 * */
bool existHostWindow();

/**
 * @brief 插入子窗口
 * */
bool insertWindow(HWND handle);


#endif //MOVESTYLE_UTILS_H
