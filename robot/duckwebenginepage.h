#ifndef DUCKWEBENGINEPAGE_H
#define DUCKWEBENGINEPAGE_H

#include <QWebEnginePage>


class DuckWebEnginePage : public QWebEnginePage
{
    Q_OBJECT
public:
    DuckWebEnginePage();
    void javaScriptConsoleMessage(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString& message, int lineNumber, const QString& sourceID);

signals:

public slots:
};

#endif // DUCKWEBENGINEPAGE_H
