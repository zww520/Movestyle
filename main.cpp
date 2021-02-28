
#include "data.h"
#include "single_data_queue.h"
#include "ffmpeger.h"
#include "video_resolver.h"
#include "controller.h"
#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <QApplication>


void qtRun(int argc,char** argv)
{
    QApplication app(argc,argv);
    MainWindow mainwindow;
    mainwindow.show();
    app.exec();
}


int main(int argc,char** argv)
{
    qtRun(argc,argv);
    return 0;
}
