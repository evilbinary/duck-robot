#include "duckwebenginepage.h"

DuckWebEnginePage::DuckWebEnginePage(){

}


void DuckWebEnginePage::javaScriptConsoleMessage(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString& message, int lineNumber, const QString& sourceID){
    QString levelTip="info";
    if(level==JavaScriptConsoleMessageLevel::WarningMessageLevel){
        levelTip="warn";
    }else if(level==JavaScriptConsoleMessageLevel::ErrorMessageLevel){
        levelTip="error";
    }
    qDebug()<<"["+levelTip+"]"<<message;
}
