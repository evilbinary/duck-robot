#include "twebengineurlrequestinterceptor.h"

WebUrlRequestInterceptor::WebUrlRequestInterceptor(QObject *parent)
    : QWebEngineUrlRequestInterceptor(parent)
{
}

void WebUrlRequestInterceptor::interceptRequest(QWebEngineUrlRequestInfo &info)
{
    QString strInfo = "";
    switch (info.resourceType())
    {
    case 0:  //Top level page
        strInfo = "ResourceTypeMainFrame";
        break;

    case 1:  //Frame
        strInfo = "ResourceTypeSubFrame";
        break;

    case 2:  //CSS stylesheet
        strInfo = "ResourceTypeStylesheet";
        break;

    case 3:  //External script
        strInfo = "ResourceTypeScript";
        break;

    case 4:  //Image
        strInfo = "ResourceTypeImage";
        break;

    case 5:  //Font
        strInfo = "ResourceTypeFontResource";
        break;

    case 6:  //Sub-resource
        strInfo = "ResourceTypeSubResource";
        break;

    case 7:  //Plugin object
        strInfo = "ResourceTypeObject";
        break;

    case 8:  //Media resource
        strInfo = "ResourceTypeMedia";
        break;

    case 9:  //Resource of dedicated worker
        strInfo = "ResourceTypeWorker";
        break;

    case 10:  //Resource of shared worker
        strInfo = "ResourceTypeSharedWorker";
        break;

    case 11:  //Explicitly requested prefetch
        strInfo = "ResourceTypePrefetch";
        break;

    case 12:  //Favicon
        strInfo = "ResourceTypeFavicon";
        break;

    case 13: //XML http request
        strInfo = "ResourceTypeXhr";
        break;

    case 14: //Ping request
        strInfo = "ResourceTypePing";
        break;

    case 15: //Resource of service worker
        strInfo = "ResourceTypeServiceWorker";
        break;

    case 16: //Unknown resource
        strInfo = "ResourceTypeUnknown";
        break;

    default:
        strInfo = "Unknown type";
        break;
    }

//    qDebug()<<info.requestMethod()<< " "<<strInfo
//        << "" << info.requestUrl().toString();

}

