//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_CONTROLLER_H
#define MOVESTYLE_CONTROLLER_H

#include <QObject>

#include "video_resolver.h"
#include "wallpaper_window.h"

/**
 * @var status_code
 * */
class Controller : public QObject
{
    Q_OBJECT
private:
    WallpaperWindow* wallpaperWindow = nullptr;
    Resolver* resolver = nullptr;
    int status_code = 0;
    int w = 0;
    int h = 0;
    bool ready = false;
public:
    explicit Controller(QObject* parent=nullptr);
    ~Controller();
    void start();
    void stop();
    void exit();
    void reset();
    void init(QString _url);
    void createWindow();
signals:
    void signals_internal_error();
};


#endif //MOVESTYLE_CONTROLLER_H
