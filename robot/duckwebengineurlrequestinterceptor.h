/**
 * 作者:evilbinary on 12/24/16.
 * 邮箱:rootdebug@163.com
 */

#ifndef DUCKWEBENGINEURLREQUESTINTERCEPTOR_H
#define DUCKWEBENGINEURLREQUESTINTERCEPTOR_H


#include <QtWebEngineWidgets>

class DuckWebUrlRequestInterceptor : public QWebEngineUrlRequestInterceptor
{
    Q_OBJECT

public:
    DuckWebUrlRequestInterceptor(QObject *parent = Q_NULLPTR);
    void interceptRequest(QWebEngineUrlRequestInfo &info);
};

#endif // TWEBENGINEURLREQUESTINTERCEPTOR_H
