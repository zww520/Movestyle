//
// Created by 18378 on 2021/2/26.
//

#ifndef MOVESTYLE_RESOLVER_H
#define MOVESTYLE_RESOLVER_H

#include <QObject>
#include <QString>

class Resolver : public QObject
{
    Q_OBJECT
public:
    explicit Resolver(QObject* parent=nullptr);
    ~Resolver() noexcept override;  // 虚函数，调用子类析构函数

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void exit() = 0;
    virtual bool init(QString _url) = 0;

signals:
    void signals_ready_refresh();  //刷新屏幕信号
    void signals_internal_error(); // 发生错误信号
};


#endif //MOVESTYLE_RESOLVER_H
