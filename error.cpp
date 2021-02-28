//
// Created by 18378 on 2021/2/27.
//

#include "error.h"


int ERROR_CODE = 0;

std::vector<QString> error_list {
        "未发生错误",
        "FFmpeger初始化错误",
        "Resolver初始化错误",
        "插入背景窗口错误"
};

QString getLastErrorStr()
{
    return error_list[ERROR_CODE];
}

int getLastErrorCode()
{
    return ERROR_CODE;
}

void setLastError(int error_code)
{
    ERROR_CODE = error_code;
}