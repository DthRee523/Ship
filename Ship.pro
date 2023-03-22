QT       += core gui network sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L"$$PWD/Eonic" -lEonic

INCLUDEPATH += \
    $$PWD/Eonic

SOURCES += \
    alarminformationwidget.cpp \
    hxfzwidget.cpp \
    hxinformaion.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    meterwidget.cpp \
    meterwidget1.cpp \
    sqlwidget.cpp \
    zhfswidget.cpp

HEADERS += \
    alarminformationwidget.h \
    colorMeneger.h \
    hxfzwidget.h \
    hxinformaion.h \
    loginwidget.h \
    mainwindow.h \
    map.h \
    meterwidget.h \
    meterwidget1.h \
    sqlwidget.h \
    zhfswidget.h

FORMS += \
    alarminformationwidget.ui \
    hxfzwidget.ui \
    hxinformaion.ui \
    loginwidget.ui \
    mainwindow.ui \
    meterwidget.ui \
    meterwidget1.ui \
    sqlwidget.ui \
    zhfswidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
