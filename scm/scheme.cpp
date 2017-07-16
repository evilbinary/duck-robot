#include "scheme.h"
#include <sstream>

#define LINE_LENGTH 1024


Scm::Scm()
{

   client = new QTcpSocket();
   connect(client,SIGNAL(connected()),SLOT(connected()));
   connect(client,SIGNAL(disconnected()),SLOT(disconnected()));
   connect(client,SIGNAL(readyRead()),this,SLOT(readyRead()));

}
void Scm::connected(){
    qDebug()<<"connected";
    isConnected=true;
}

void Scm::disconnected(){
    qDebug()<<"disconnected";
    isConnected=false;
}

void Scm::eval(QString exp,function<void(QVariant &ret) >fun){
    if(client->state()== QAbstractSocket::UnconnectedState||client->state()==QAbstractSocket::ClosingState){
        client->abort();
        QSettings *configIniRead = new QSettings("duck.ini", QSettings::IniFormat);
        QString ip = configIniRead->value("/scheme/ip","127.0.0.1").toString();
        int port = configIniRead->value("/scheme/port",8100).toInt();
        timeOut=configIniRead->value("/scheme/port",timeOut).toInt();
        client->connectToHost(QHostAddress(ip), port);
    }
    callback=fun;
    qDebug()<<"write="<<client->write(exp.toStdString().c_str())<<" isConnected="<<isConnected<<" erro="<<client->errorString();


}
void Scm::readyRead(){
    if(callback!=NULL){
        QVariant ret(client->readAll());
        qDebug()<<"client->readAll()="<<ret;
        callback(ret);
    }
}

Scm::~Scm(){

}
