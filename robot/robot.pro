TEMPLATE = app
TARGET = duck

QT += core gui webenginewidgets xml

SOURCES += main.cpp \
    duckwebenginepage.cpp \
    duckwebcallback.cpp \
    duckwebengineurlrequestinterceptor.cpp

RESOURCES += \
    resources.qrc


target.path = $$[QT_INSTALL_EXAMPLES]/duck/duck
INSTALLS += target

HEADERS += \
    main.h \
    duckwebenginepage.h \
    duckwebcallback.h \
    duckwebengineurlrequestinterceptor.h


RESOURCES =resources.qrc

