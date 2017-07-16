#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T21:51:01
#
#-------------------------------------------------

QT       -= core gui
QT +=network

TARGET = scheme
TEMPLATE = lib

DEFINES += SCM_LIBRARY

SOURCES += \
    scheme.cpp

HEADERS +=\
        scm_global.h \
    scheme.h

UNAME_S =

unix {
    target.path = /usr/lib
    INSTALLS += target
}

