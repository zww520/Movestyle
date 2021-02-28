//
// Created by 18378 on 2021/2/27.
//

#include "utils.h"

static HWND win_handle = nullptr;

bool createHostWindow()
{
    if(existHostWindow())
        return true;
    HWND progman = nullptr;
    progman = FindWindow("Progman", "Program Manager");
    if(progman==nullptr)
    {
        return false;
    }
    HWND workerW = nullptr;
    SendMessageTimeout(
            progman,
            0x52c,
            NULL,
            NULL,
            SMTO_NORMAL,
            1000,
            nullptr);
    return existHostWindow();
}


BOOL CALLBACK enumWindowsProc(HWND top_handle,LPARAM lprama)
{
    HWND handle = FindWindowEx(
            top_handle,
            nullptr,
            "SHELLDLL_DefView",
            nullptr);
    if(handle!=nullptr)
    {
        win_handle =  FindWindowEx(
                nullptr,
                top_handle,
                "WorkerW",
                nullptr);
    }
    return true;
}

bool existHostWindow()
{
    if(win_handle!=nullptr)
        return true;
    EnumWindows(enumWindowsProc, NULL);
    if(win_handle==nullptr)
        return false;
    return true;
}

bool insertWindow(HWND handle)
{
    HWND res;
    createHostWindow();
    if(existHostWindow())
    {
        res = SetParent(handle,win_handle);
        if(res!=nullptr)
            return true;
    }
    return false;
}