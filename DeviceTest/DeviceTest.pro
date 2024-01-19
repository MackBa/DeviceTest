QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    information.cpp \
    main.cpp \
    mytemplate.cpp \
    newtemplate.cpp \
    plotinf.cpp \
    readtemplate.cpp \
    widget.cpp

HEADERS += \
    baseclass.h \
    information.h \
    mytemplate.h \
    newtemplate.h \
    plotinf.h \
    readtemplate.h \
    widget.h

FORMS += \
    information.ui \
    newtemplate.ui \
    plotinf.ui \
    readtemplate.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
