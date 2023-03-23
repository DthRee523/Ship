QT       += core gui network sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L"$$PWD/Eonic" -lEonic

#自动复制配置文件
CONFIG += file_copies
config_file.files = $$PWD/config.ini
config_file.path = $$OUT_PWD
COPIES += config_file

INCLUDEPATH += \
    $$PWD/Eonic

SOURCES += \
    alarminformationwidget.cpp \
    hxfzwidget.cpp \
    hxinformaion.cpp \
    led.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    meterwidget.cpp \
    meterwidget1.cpp \
    network.cpp \
    sqlwidget.cpp \
    zhfswidget.cpp

HEADERS += \
    alarminformationwidget.h \
    colorMeneger.h \
    hxfzwidget.h \
    hxinformaion.h \
    led.h \
    loginwidget.h \
    mainwindow.h \
    map.h \
    meterwidget.h \
    meterwidget1.h \
    network.h \
    sqlwidget.h \
    zhfswidget.h

FORMS += \
    alarminformationwidget.ui \
    hxfzwidget.ui \
    hxinformaion.ui \
    led.ui \
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
