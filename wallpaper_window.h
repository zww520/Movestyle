//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_WALLPAPER_WINDOW_H
#define MOVESTYLE_WALLPAPER_WINDOW_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QEvent>
class WallpaperWindow : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit WallpaperWindow(QWidget* parent=nullptr);
    ~WallpaperWindow() override;
protected:
    void paintEvent(QPaintEvent *e) override ;
    void  resizeEvent(QResizeEvent *e) override ;
    bool eventFilter(QObject *watched, QEvent *event) override ;
public slots:
    void slot_update_window();
};


#endif //MOVESTYLE_WALLPAPER_WINDOW_H
