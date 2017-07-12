/**
 * 作者:evilbinary on 12/24/16.
 * 邮箱:rootdebug@163.com
 */

#include <QApplication>
#include <QtWebEngineWidgets>
#include "main.h"
#include "duckwebengineurlrequestinterceptor.h"
#include<QDebug>
#include "duckwebcallback.h"
#include "duckwebenginepage.h"





int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    QString userAgent="Mozilla/5.0 (Windows; U; Windows NT 5.2) AppleWebKit/525.13 (KHTML, like Gecko) Version/3.1";
    //QString userAgent="Mozilla/5.0 (Linux; U; Android 4.0.3; zh-cn; M032 Build/IML74K) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30";


    DuckWebUrlRequestInterceptor *webInterceptor = new DuckWebUrlRequestInterceptor();
    QWebEngineProfile::defaultProfile()->setRequestInterceptor(webInterceptor);
    QWebEngineProfile::defaultProfile()->setHttpUserAgent(userAgent);

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    DuckWebEnginePage* duckenginePage=new DuckWebEnginePage();
    QWebEngineView *view=new QWebEngineView();
    view->setPage(duckenginePage);

    DuckWebCallBack *webCallback=new DuckWebCallBack(view);

//    QWebEngineProfile::defaultProfile()->setProperty("device-width","1280");
//    QWebEngineProfile::defaultProfile()->setProperty("width","10280");
//    view->page()->settings()->setAttribute(QWebEngineSettings::WebAttribute::LocalContentCanAccessRemoteUrls,true);

    QObject::connect(view, SIGNAL(loadFinished(bool)),webCallback,SLOT(finishLoading(bool)));
    view->setUrl(QUrl("http://w.qq.com/"));
    view->resize(420, 640);


    view->show();

    return app.exec();

}
