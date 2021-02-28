//
// Created by 18378 on 2021/2/27.
//

#ifndef MOVESTYLE_ERROR_H
#define MOVESTYLE_ERROR_H

#define NONE_EROOR 0
#define FFMPEGER_ERROR 1
#define RESOLVER_ERROR 2
#define WALLPAPERWINDOW_ERROR 3


#include <QString>
#include <vector>



QString getLastErrorStr();


int getLastErrorCode();

void setLastError(int error_code);

#endif //MOVESTYLE_ERROR_H
