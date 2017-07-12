TEMPLATE = app
TARGET = duck

QT += core gui webenginewidgets xml

SOURCES += main.cpp \
    twebengineurlrequestinterceptor.cpp \
    webcallback.cpp

RESOURCES += \
    resources.qrc


target.path = $$[QT_INSTALL_EXAMPLES]/duck/duck
INSTALLS += target

HEADERS += \
    main.h \
    twebengineurlrequestinterceptor.h \
    webcallback.h


RESOURCES =resources.qrc

