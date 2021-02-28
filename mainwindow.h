//
// Created by 18378 on 2021/2/27.
//

#ifndef MOVESTYLE_MAINWINDOW_H
#define MOVESTYLE_MAINWINDOW_H


#include "controller.h"

#include <QMainWindow>
#include <QWidget>
#include <QSystemTrayIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @var status_code
 * */
class MainWindow : public QMainWindow
{
Q_OBJECT
private:
    int status_code = 0;
    bool up = false;
    QString url;
    Controller *controller;
    QSystemTrayIcon* tray;
    QIcon* icon;
    QMenuBar* menu_bar;
    QAction* about_action;
    QAction* help_action;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void reset();
protected:
    void changeEvent(QEvent *event)override;
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::MainWindow *ui;
private slots:
    void slots_choosed_button_click();
    void slots_stop_button_click();
    void slots_start_button_click();
    void slots_exit_button_click();
    void slots_about_action_triggered();
    void slots_help_action_triggered();
    void slots_tray_action_triggered();
    void slots_show_error_message();
};


#endif //MOVESTYLE_MAINWINDOW_H
