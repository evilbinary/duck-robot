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

class WebCallBack:public QObject
{
    Q_OBJECT

public:
    WebCallBack(QWebEngineView *view);


public Q_SLOTS:
    void finishLoading(bool);
    void showMsgBox(QString msg);
    void javaScriptConsoleMessage(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString& message, int lineNumber, const QString& sourceID);
    void onTimerOut();
    void loadFrame();

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
    QWebEngineView * webEngineView;
};

#endif // WEBCALLBACK_H
