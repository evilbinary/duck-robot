#include "scheme.h"
#include <sstream>

#define LINE_LENGTH 1024


Scm::Scm()
{

   client = new QTcpSocket();
   client->connect(client,SIGNAL(connected()),SLOT(connected()));
   client->connect(client,SIGNAL(disconnected()),SLOT(disconnected()));

}
void Scm::connected(){
    isConnected=true;
}

void Scm::diconnected(){
    isConnected=false;
}

string Scm::eval(string exp){
    if(!isConnected){
        client->reset();
        QSettings *configIniRead = new QSettings("duck.ini", QSettings::IniFormat);
        QString ip = configIniRead->value("/scheme/ip","127.0.0.1").toString();
        int port = configIniRead->value("/scheme/port",8100).toInt();
        client->connectToHost(QHostAddress(ip), port);
    }
    FILE *file;
    //ostringstream oss;
    qDebug()<<"write="<<client->write(exp.c_str())<<" isConnected="<<isConnected;

    if(client->waitForReadyRead()){
         return client->readAll().toStdString();
    }
    return "";
}

Scm::~Scm(){

}
