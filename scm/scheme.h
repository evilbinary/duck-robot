#ifndef SCM_H
#define SCM_H

#include "scm_global.h"
#include <iostream>
#include <QtNetwork>

using namespace std;

class  Scm
{
private:
    QTcpSocket *client;
    bool isConnected=false;
public:
    Scm();
    string eval(string exp);
    void connected();
    void diconnected();

    ~Scm();
};

#endif // SCM_H
