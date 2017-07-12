#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T21:51:01
#
#-------------------------------------------------

QT       -= core gui

TARGET = scm
TEMPLATE = lib

DEFINES += SCM_LIBRARY

SOURCES += scm.cpp

HEADERS += scm.h\
        scm_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
