/**
 * 作者:evilbinary on 12/24/16.
 * 邮箱:rootdebug@163.com
 */

#include "duckwebcallback.h"
#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QTimer>
#include <QDomDocument>




using namespace std;

DuckWebCallBack::DuckWebCallBack(QWebEngineView *view)
{
    this->webEngineView=view;
    QWebChannel *channel = new QWebChannel(webEngineView->page());
    channel->registerObject(QStringLiteral("bridge"), (QObject*)this);
    webEngineView->page()->setWebChannel(channel);

    QFile webChannelFile;
    webChannelFile.setFileName(":/qwebchannel.js");
    webChannelFile.open(QIODevice::ReadOnly);
    QString webChannelJs = webChannelFile.readAll();
    webChannelFile.close();

    webChannelJs.append("var webChannel=new QWebChannel(qt.webChannelTransport, function(channel) { \
                        window.bridge = channel.objects.bridge; \
            console.log(channel.objects.bridge);\
    });");
    webEngineView->page()->runJavaScript(webChannelJs,[=](const QVariant &v){
        qDebug()<<"ret webChannelJs===>"<<v<<" "<<v.toString();
    });

    scm=new Scm();

}

void DuckWebCallBack::finishLoading(bool b){
    qDebug()<<"finishLoading="<<b<<endl;


    QFile file;
    file.setFileName(":/jquery-3.2.1.min.js");
    file.open(QIODevice::ReadOnly);
    QString jQuery = file.readAll();
    jQuery.append("\n var jq = jQuery.noConflict();");
    file.close();

    webEngineView->page()->runJavaScript(jQuery,[=](const QVariant &v){
        qDebug()<<"ret jQuery===>"<<v<<" "<<v.toString();
    });

    QFile webFile;
    webFile.setFileName(":/web.js");
    webFile.open(QIODevice::ReadOnly);
    QString webJs = webFile.readAll();
    webFile.close();

    webEngineView->page()->runJavaScript(webJs,[=](const QVariant &v){
        qDebug()<<"ret webJs===>"<<v<<" "<<v.toString();
    });


    //    QWebEngineScript script;
    //            script.setSourceCode(webChannelJs);
    //            script.setName("qwebchannel.js");
    //            script.setWorldId(QWebEngineScript::MainWorld);
    //            script.setInjectionPoint(QWebEngineScript::DocumentCreation);
    //            script.setRunsOnSubFrames(true);
    //    webEngineView->page()->scripts().insert(script);


    //    webEngineView->page()->runJavaScript("showMessage('abc');",[=](const QVariant &v){
    //        qDebug()<<"showMessage===>"<<v<<" "<<v.toString();
    //    });

    //    QString js="document.getElementsByTagName('body')";

    //    webEngineView->page()->runJavaScript(js,[=](const QVariant &v){
    //        qDebug()<<"jq===>"<<v<<" "<<v.toString();
    //    });

    //    QTimer* timer = new QTimer();
    //    timer->setInterval(5000);
    //    timer->start();
    //    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));


}


void DuckWebCallBack::recieveGroupMessage(long gid,long uid,QString groupName,QString nick,QString message){
    qDebug()<<gid<<" "<<uid<<" "<<groupName<<" "<<nick<<" "<<message;

    if(groupName=="机器人大战"){
        if(message.startsWith("$")){

            string exp=message.remove("$").toUtf8().toStdString();
            string  ret=scm->eval(exp);
            QString eret=QString::fromStdString(ret);
            qDebug()<<"exp=>"<<message.remove("$")<<" ret="<<eret;
            QString js=QString("sendGroupMessage(%1,'%2');").arg(gid).arg(eret);

            webEngineView->page()->runJavaScript(js,[=](const QVariant &v){
                qDebug()<<"sendGroupMessage===>"<<v<<" "<<v.toString();
            });
        }
    }

}

void DuckWebCallBack::onTimerOut(){
    //    webEngineView->page()->toHtml([=](const QVariant &v){
    //        qDebug()<<"toHtml===>"<<v<<" "<<v.toString();
    //    });

}




void DuckWebCallBack::showMsgBox(QString msg){
    qDebug()<<"showMsgBox"<<msg;
    QMessageBox::information(NULL,"",msg);
}
void DuckWebCallBack::loadFrame(){
    qDebug()<<"loadFrame";
    //    webEngineView->page()->toHtml([=](const QVariant &v){
    //        qDebug()<<"toHtml===>"<<v<<" "<<v.toString();

    //        int pos = 0;
    //        QString str =v.toString();
    //        QRegExp rx("<img.*src=(.*?)[^>]*?>");
    //        while ((pos = rx.indexIn(str, pos)) != -1) {
    //            //list << rx.cap(1);
    //            qDebug()<<rx.cap(1)<<" "<<rx.cap(2);

    //            pos += rx.matchedLength();
    //        }

    //        //        QDomDocument doc;
    //        //        qDebug()<<"1==>";
    //        //        QString errorMsg;
    //        //        if(!doc.setContent(v.toString(), false,&errorMsg)){
    //        //            qDebug()<<"errorMsg=>"<<errorMsg;
    //        //            return ;
    //        //        }
    //        //        qDebug()<<"2==>";

    //        //        QDomElement root = doc.documentElement();
    //        //        QDomNodeList nodelist=root.elementsByTagName("img");
    //        //        qDebug()<<"nodelist.size==>"<<nodelist.size();
    //        //        if (nodelist.isEmpty())
    //        //            return;
    //        //        for (int i=0; i<nodelist.size(); i++)
    //        //        {
    //        //            QString src=nodelist.at(i).toElement().attribute("src");
    //        //            //text=nodelist.at(i).toElement().text());
    //        //            qDebug()<<src;
    //        //        }
    //    });

}
