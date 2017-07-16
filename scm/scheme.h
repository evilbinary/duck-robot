#ifndef SCM_H
#define SCM_H

#include "scm_global.h"
#include <iostream>
#include <QtNetwork>
#include <QObject>
#include <functional>


using namespace std;

class  Scm:public QObject
{
    Q_OBJECT
private:
    QTcpSocket *client;
    bool isConnected=false;
    int timeOut=1000;
    std::function <void (QVariant &ret) > callback=NULL;

public:
    Scm();
    void eval(QString exp,function<void(QVariant &ret) >);
    ~Scm();

public Q_SLOTS:
    void connected();
    void disconnected();
    void readyRead();


};

#endif // SCM_H
