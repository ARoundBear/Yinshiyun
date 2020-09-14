QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blowuplabel.cpp \
    cmythread.cpp \
    main.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    selectfourdialog.cpp \
    selecttwodialog.cpp

HEADERS += \
    blowuplabel.h \
    cmythread.h \
    mainwindow.h \
    mylabel.h \
    selectfourdialog.h \
    selecttwodialog.h

FORMS += \
    mainwindow.ui \
    selectfourdialog.ui \
    selecttwodialog.ui

INCLUDEPATH += \
    D:/QT_Project/qtTestProject/MyQPlayer/YingshiyunDLL/inc

LIBS += -LD:/QT_Project/qtTestProject/MyQPlayer/YingshiyunDLL/lib/win32 -lAnalyzeData -lAudioIntercom -lecdhCryption -lhlog -lhpr -llibCASClient -llibcurl\
    -llibeay32 -llibGetHDSign -llibPPVClient2 -llibstreamclient -lmbedTLS -lMidPage -lminiupnpc -lNetStream -lOpenNetStream -lopensslwrap -lpaho-mqtt3c -lPlayCtrl -lpthreadVC2 -lPushClient\
    -lssleay32 -lStunClientLib -lSystemTransform -lTTSClient -ludt

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
