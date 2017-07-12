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
