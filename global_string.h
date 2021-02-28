//
// Created by 18378 on 2021/2/28.
//

#ifndef MOVESTYLE_GLOBAL_STRING_H
#define MOVESTYLE_GLOBAL_STRING_H

#include <QString>

namespace locale {
    static QString about = "关于";
    static QString help = "帮助";
    static QString error = "错误";
    static QString about_text = "<h2 style=\"text-align: center\">关于MoveStyle</h2>"
                                "<p>这是一款开源软件，开源地址@https://github.com/zww520/Movestyle</p>"
                                "<h4>Version:1.0.0</h4>";
    static QString help_text = "<h2 style=\"text-align: center\">如何使用</h2>\n"
                               "<p>确定:选择视频文件</p>\n"
                               "<p>开始:开始渲染动态壁纸</p>\n"
                               "<p>暂停:停止渲染</p>\n"
                               "<p>退出:结束动态壁纸渲染</p>";
}

#endif //MOVESTYLE_GLOBAL_STRING_H
