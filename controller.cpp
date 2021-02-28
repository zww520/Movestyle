//
// Created by 18378 on 2021/2/26.
//

#include "controller.h"
#include "utils.h"
#include "error.h"

#include <QDebug>
#include <QScreen>
#include <QApplication>

Controller::Controller(QObject* parent) : QObject(parent)
{
    createWindow();
}

Controller::~Controller() noexcept
{
    if(wallpaperWindow!=nullptr)
        wallpaperWindow->deleteLater();
    if(resolver!=nullptr)
        delete resolver;
    wallpaperWindow = nullptr;
    resolver = nullptr;
}

void Controller::reset()
{
    exit();
    ready = false;
}

void Controller::init(QString _url)
{
    if(!ready)
        return;
    if(resolver!=nullptr)
        delete resolver;
    resolver = new VideoResolver;
    connect(resolver,&Resolver::signals_internal_error,this,&Controller::signals_internal_error);
    connect(resolver,&Resolver::signals_ready_refresh,wallpaperWindow,&WallpaperWindow::slot_update_window);
    resolver->init(_url);
    wallpaperWindow->show();
}

void Controller::start()
{
    if(!ready)
        return;
    if(resolver!=nullptr)
        resolver->start();
}

void Controller::stop()
{
    if(!ready)
        return;
    if(resolver!=nullptr)
        resolver->stop();
}

void Controller::exit()
{
    if(resolver!=nullptr)
    {
        disconnect(resolver,&Resolver::signals_internal_error,this,&Controller::signals_internal_error);
        disconnect(resolver,&Resolver::signals_ready_refresh,wallpaperWindow,&WallpaperWindow::slot_update_window);
        delete resolver;
        resolver = nullptr;
        wallpaperWindow->hide();
    }
}

void Controller::createWindow()
{
    auto sc = QApplication::screens();
    w = sc[0]->availableGeometry().width();
    h = sc[0]->availableGeometry().height();
    wallpaperWindow = new WallpaperWindow;
    wallpaperWindow->resize(w,h);
    wallpaperWindow->windowHandle();
    if(!insertWindow((HWND)wallpaperWindow->winId()))
    {
        ready = false;
        setLastError(WALLPAPERWINDOW_ERROR);
        emit signals_internal_error();
    }
    else
    {
        status_code = 0;
        ready = true;
    }
}