/**
 * 作者:evilbinary on 12/24/16.
 * 邮箱:rootdebug@163.com
 */

#ifndef TWEBENGINEURLREQUESTINTERCEPTOR_H
#define TWEBENGINEURLREQUESTINTERCEPTOR_H


#include <QtWebEngineWidgets>

class WebUrlRequestInterceptor : public QWebEngineUrlRequestInterceptor
{
    Q_OBJECT

public:
    WebUrlRequestInterceptor(QObject *parent = Q_NULLPTR);
    void interceptRequest(QWebEngineUrlRequestInfo &info);
};

#endif // TWEBENGINEURLREQUESTINTERCEPTOR_H
