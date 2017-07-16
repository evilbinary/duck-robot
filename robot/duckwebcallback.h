/**
 * 作者:evilbinary on 12/24/16.
 * 邮箱:rootdebug@163.com
 */
#ifndef WEBCALLBACK_H
#define WEBCALLBACK_H

#include <QObject>
#include <QDebug>
#include <QtWebEngineWidgets>
#include <QWebEnginePage>
#include "scheme.h"


class DuckWebCallBack:public QObject
{
    Q_OBJECT

public:
    DuckWebCallBack(QWebEngineView *view);


public Q_SLOTS:
    void finishLoading(bool);
    void showMsgBox(QString msg);
    void onTimerOut();
    void loadFrame();

    void recieveGroupMessage(long gid,long uid,QString groupName,QString nick,QString message);

//       void adjustLocation();
//       void changeLocation();
//       void adjustTitle();
//       void setProgress(int p);

//       void viewSource();

//       void highlightAllLinks();
//       void rotateImages(bool invert);
//       void removeGifImages();
//       void removeInlineFrames();
//       void removeObjectElements();
//       void removeEmbeddedElements();


private:
    Scm* scm;
    QWebEngineView * webEngineView;
};

#endif // WEBCALLBACK_H
