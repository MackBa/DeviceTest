QT       += core gui serialport printsupport charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/Chart/chartwork.cpp \
    src/Chart/displayplot.cpp \
    src/Chart/qcustomplot.cpp \
    src/Communicate/tcpcommunicate.cpp \
    src/Communicate/tcpmodule.cpp \
    src/FileSave/BDFHeader.cpp \
    src/FileSave/filemodule.cpp \
    src/FileSave/filesave.cpp \
    src/Filter/DesignButter/filterDesign.cpp \
    src/Filter/DesignButter/src/DesignButter.c \
    src/Filter/DesignButter/src/DesignButter_emxutil.c \
    src/Filter/DesignButter/src/rtGetInf.c \
    src/Filter/DesignButter/src/rtGetNaN.c \
    src/Filter/DesignButter/src/rt_nonfinite.c \
    src/Filter/filtermodule.cpp \
    src/Filter/filterwork.cpp \
    src/Template/information.cpp \
    src/Template/mytemplate.cpp \
    src/Template/newtemplate.cpp \
    src/Template/plotinf.cpp \
    src/Template/readtemplate.cpp \
    widget.cpp

HEADERS += \
    ConstData.h \
    baseclass.h \
    src/Chart/chartwork.h \
    src/Chart/displayplot.h \
    src/Chart/qcustomplot.h \
    src/Communicate/tcpcommunicate.h \
    src/Communicate/tcpmodule.h \
    src/FileSave/BDFHeader.h \
    src/FileSave/filemodule.h \
    src/FileSave/filesave.h \
    src/Filter/DesignButter/filterDesign.h \
    src/Filter/DesignButter/src/DesignButter.h \
    src/Filter/DesignButter/src/DesignButter_emxutil.h \
    src/Filter/DesignButter/src/DesignButter_types.h \
    src/Filter/DesignButter/src/rtGetInf.h \
    src/Filter/DesignButter/src/rtGetNaN.h \
    src/Filter/DesignButter/src/rt_defines.h \
    src/Filter/DesignButter/src/rt_nonfinite.h \
    src/Filter/DesignButter/src/rtwtypes.h \
    src/Filter/filter.h \
    src/Filter/filterbank.h \
    src/Filter/filtermodule.h \
    src/Filter/filterwork.h \
    src/Template/information.h \
    src/Template/mytemplate.h \
    src/Template/newtemplate.h \
    src/Template/plotinf.h \
    src/Template/readtemplate.h \
    widget.h
INCLUDEPATH += \
        src/Chart/ \
        "D:\Program Files\MATLAB\R2023a\extern\include"

FORMS += \
    src/Chart/displayplot.ui \
    src/Communicate/tcpmodule.ui \
    src/FileSave/filemodule.ui \
    src/Filter/filtermodule.ui \
    src/Template/information.ui \
    src/Template/newtemplate.ui \
    src/Template/plotinf.ui \
    src/Template/readtemplate.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
