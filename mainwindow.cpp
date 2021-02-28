//
// Created by 18378 on 2021/2/27.
//

#include "mainwindow.h"
#include "global_string.h"
#include "error.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <QMenuBar>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MoveStyle");

    icon = new QIcon("C:\\Users\\18378\\CLionProjects\\qttest\\MoveStyle.ico");

    this->setWindowTitle("MoveStyle");
    this->setWindowIcon(*icon);
    controller = new Controller;

    menu_bar = new QMenuBar(this);
    menu_bar->resize(this->width(),menu_bar->height());
    about_action = menu_bar->addAction(locale::about);
    help_action = menu_bar->addAction(locale::help);

    tray = new QSystemTrayIcon(this);
    tray->setToolTip("MoveStyle");
    tray->setIcon(*icon);

    connect(about_action,&QAction::triggered,this,&MainWindow::slots_about_action_triggered);
    connect(help_action,&QAction::triggered,this,&MainWindow::slots_help_action_triggered);
    connect(tray,&QSystemTrayIcon::activated,this,&MainWindow::slots_tray_action_triggered);

    connect(ui->choose_button, &QPushButton::clicked, this, &MainWindow::slots_choosed_button_click, Qt::UniqueConnection);
    connect(ui->start_button, &QPushButton::clicked, this, &MainWindow::slots_start_button_click, Qt::UniqueConnection);
    connect(ui->stop_button, &QPushButton::clicked, this, &MainWindow::slots_stop_button_click, Qt::UniqueConnection);
    connect(ui->exit_button, &QPushButton::clicked, this, &MainWindow::slots_exit_button_click, Qt::UniqueConnection);
    connect(controller,&Controller::signals_internal_error,this,&MainWindow::slots_show_error_message);
}

MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

void MainWindow::slots_choosed_button_click()
{
    QString _url = QFileDialog::getOpenFileName(
            this,tr("选择文件")
    );
    if(!_url.isEmpty() && url!=_url)
    {
        url = _url;
        ui->filename_label->setText(url);
        up = true;
    }
}

void MainWindow::slots_stop_button_click()
{
    controller->stop();
}

void MainWindow::slots_start_button_click()
{
    if(up)
    {
        up = false;
        controller->init(url);
    }
    controller->start();
}

void MainWindow::slots_exit_button_click()
{
    controller->exit();
    url = "";
    ui->filename_label->setText("请选择文件");
    up = false;
}


void MainWindow::slots_about_action_triggered()
{
    QMessageBox messageBox(
            QMessageBox::NoIcon,
            locale::about,
            locale::about_text,
            QMessageBox::Ok,
            this,
            Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    messageBox.show();
    messageBox.exec();
}

void MainWindow::slots_help_action_triggered()
{
    QMessageBox messageBox(
            QMessageBox::NoIcon,
            locale::help,
            locale::help_text,
            QMessageBox::Ok,
            this,
            Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    messageBox.show();
    messageBox.exec();
}

void MainWindow::slots_tray_action_triggered()
{
    show();
    this->setWindowState(Qt::WindowNoState);
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange)
    {
        if(this->windowState()==Qt::WindowNoState)
        {
            tray->hide();
        }
        else if(this->windowState()==Qt::WindowMinimized)
        {
            tray->show();
            hide();
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    controller->exit();
    tray->hide();
    tray->deleteLater();
}

void MainWindow::slots_show_error_message()
{
    QMessageBox messageBox(
            QMessageBox::NoIcon,
            locale::error,
            getLastErrorStr(),
            QMessageBox::Ok,
            this,
            Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    messageBox.show();
    messageBox.exec();
    url = "";
    ui->filename_label->setText("请选择文件");
    up = false;
}

void MainWindow::reset()
{

}