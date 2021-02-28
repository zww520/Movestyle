//
// Created by 18378 on 2021/2/26.
//

#include "wallpaper_window.h"
#include "single_data_queue.h"

#include <QPainter>
#include <QDebug>

WallpaperWindow::WallpaperWindow(QWidget* parent) : QOpenGLWidget(parent,Qt::FramelessWindowHint)
{

}

WallpaperWindow::~WallpaperWindow() noexcept
{

}

void WallpaperWindow::paintEvent(QPaintEvent *e)
{
    SingleDataQueue& que = SingleDataQueue::getInstance();
    const Data& frame = que.front();

    QImage img(frame.ptr,frame.w,frame.h,QImage::Format_RGB888);
    QPainter painter;
    painter.begin(this);
    painter.drawImage(QRect(0,0,this->width(),this->height()),img);
    painter.end();
    que.pop();
}

void WallpaperWindow::resizeEvent(QResizeEvent *e)
{

}

bool WallpaperWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::Paint)
        return true;
    return false;
}

void WallpaperWindow::slot_update_window()
{
    this->update();
}